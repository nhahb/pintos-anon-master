#include "userprog/syscall.h"
#include <stdio.h>
#include <syscall-nr.h>
#include "threads/interrupt.h"
#include "threads/vaddr.h"
#include "filesys/inode.h"
#include "filesys/directory.h"
#include "filesys/file.h"
#include "filesys/filesys.h"
#include "threads/thread.h"

#define under_phys_base(addr) if((void*)addr >= PHYS_BASE) sys_exit(-1);
#define esp_under_phys_base(f, args_num) under_phys_base(((int*)(f->esp)+args_num+1))
#define check_fd(fd, fail, f) if(fd < 0 || fd >= FD_MAX) {f->eax = fail; break;}

static void syscall_handler (struct intr_frame *);

bool sys_chdir(char *path, struct intr_frame *f);
bool sys_mkdir(char *path, struct intr_frame *f);
bool sys_readdir(int fd, char *path, struct intr_frame *f);
bool sys_isdir(int fd, struct intr_frame *f);
int sys_inumber(int fd, struct intr_frame *f);

void
syscall_init (void) 
{
  intr_register_int (0x30, 3, INTR_ON, syscall_handler, "syscall");
}

static void
syscall_handler (struct intr_frame *f UNUSED) 
{
  int sys_vector;
  sys_vector=*(int *)(f->esp);
  switch(sys_vector)
  {
  case SYS_EXIT:
    if ((void *)((int *)f->esp + 1) >= PHYS_BASE)
      sys_exit (-1);
    else
      sys_exit (*((int *)f->esp + 1));
    break;
  case SYS_CHDIR:
    esp_under_phys_base(f, 1);
    sys_chdir((char*)*((int *)f->esp + 1), f);
    break;
  case SYS_MKDIR:
    esp_under_phys_base(f, 1);
    sys_mkdir((char*)*((int *)f->esp + 1), f);
    break;
  case SYS_READDIR:
    esp_under_phys_base(f, 2);
    check_fd(*((int *)f->esp + 1), false, f);
    sys_readdir(*((int *)f->esp + 1), (char*)*((int *)f->esp + 2), f);
    break;
  case SYS_ISDIR:
    esp_under_phys_base(f, 1);
    check_fd(*((int *)f->esp + 1), false, f);
    sys_isdir(*((int *)f->esp + 1), f);
    break;
  case SYS_INUMBER:
    esp_under_phys_base(f, 1);
    check_fd(*((int *)f->esp + 1), false, f);
    sys_inumber(*((int *)f->esp + 1), f);
  }
}

bool sys_chdir(char* path, struct intr_frame *f)
{
    bool success = filesys_chdir(path);
    f->eax = success;
    return success;
}

bool sys_mkdir(char* path, struct intr_frame *f)
{
    bool success = filesys_create(path, 0, true);
    f->eax = success;
    return success;
  }

bool sys_readdir(int fd, char* path, struct intr_frame *f)
{
    f->eax = false;
    ASSERT (fd >= 0 && fd < FD_MAX);
    
    struct file* file = thread_current()->fd_list[fd];
    if (file == NULL) return false;
    
    struct inode* inode = file_get_inode(file);
    if(inode == NULL) return false;
    if(!inode_is_dir(inode)) return false;
    
    // struct dir* dir = dir_open(inode);
    struct dir* dir = (struct dir*) file;
    // if(dir == NULL) return false;
    if(!dir_readdir(dir, path)) return false;
    
    f->eax = true;
    return true;
}

bool sys_isdir(int fd, struct intr_frame *f)
{
    f->eax = false;
    ASSERT (fd >= 0 && fd < FD_MAX);

    struct file* file = thread_current()->fd_list[fd];
    if (file == NULL) return false;

    struct inode* inode = file_get_inode(file);
    if(inode == NULL) return false;
    if(!inode_is_dir(inode)) return false;
    
    f->eax = true;
    return true;
}

int sys_inumber(int fd, struct intr_frame *f)
{
    f->eax = -1;
    ASSERT (fd >= 0 && fd < FD_MAX);

    struct file* file = thread_current()->fd_list[fd];
    if (file == NULL) return -1;

    struct inode* inode = file_get_inode(file);
    if(inode == NULL) return -1;

    block_sector_t inumber = inode_get_inumber(inode);
    f->eax = inumber;
    return inumber;
}

void
sys_exit (int status)
{
  struct thread *t = thread_current();
  int fd;
  
  t->exit_code = status;
  t->end = true;

  for (fd=0; fd < FD_MAX; fd++){ // close all open fd
    if (t->fd_list[fd] != NULL)
    {
      struct inode* inode = file_get_inode(t->fd_list[fd]);

      if(inode == NULL)
        continue;

      if(inode_is_dir(inode))
        dir_close(t->fd_list[fd]);
      else
        file_close (t->fd_list[fd]);

      t->fd_list[fd] = NULL;
    }
  }
}