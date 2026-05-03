#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main() {
    int fd = open("t2.txt", O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    pid_t pid = fork();

    if (pid == 0) {
        char buf[6];
        read(fd, buf, 5);
        buf[5] = '\0';
        printf("Child: %s\n", buf);
    } else {
        wait(NULL);
        char buf[6];
        read(fd, buf, 5);
        buf[5] = '\0';
        printf("Parent: %s\n", buf);
    }

    close(fd);
    return 0;
}
