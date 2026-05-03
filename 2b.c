#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int my_system(char *cmd) {
    pid_t pid = fork();

    if (pid == 0) {
        execl("/bin/sh", "sh", "-c", cmd, NULL);
        exit(1);
    } else {
        int status;
        wait(&status);
        return status;
    }
}

int main() {
    printf("Executing ls -l\n");
    my_system("ls -l");
    return 0;
}
