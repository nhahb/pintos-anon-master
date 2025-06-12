#include <syscall.h>
#include <stdio.h>
#include <string.h>

int
main(void)
{
    printf("Testing directory operations...\n");

    /* Tạo thư mục */
    if (mkdir("mydir")) {
        printf("Created directory 'mydir' successfully\n");
    } else {
        printf("Failed to create directory 'mydir'\n");
    }

    /* Thay đổi thư mục hiện tại */
    if (chdir("mydir")) {
        printf("Changed directory to 'mydir' successfully\n");
    } else {
        printf("Failed to change directory to 'mydir'\n");
    }

    /* Tạo một file trong thư mục mới */
    int fd = open("myfile");
    if (fd != -1) {
        printf("Created file 'myfile' in 'mydir'\n");
        close(fd);
    } else {
        printf("Failed to create file 'myfile'\n");
    }

    /* Quay lại thư mục gốc */
    if (chdir("/")) {
        printf("Changed directory back to root successfully\n");
    } else {
        printf("Failed to change directory to root\n");
    }

    /* Xóa thư mục */
    if (rmdir("mydir")) {
        printf("Removed directory 'mydir' successfully\n");
    } else {
        printf("Failed to remove directory 'mydir'\n");
    }

    printf("Test completed\n");
    return 0;
}