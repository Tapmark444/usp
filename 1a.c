#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    off_t size = lseek(fd, 0, SEEK_END);

    for (off_t i = 1; i <= size; i++) {
        lseek(fd, -i, SEEK_END);
        char c;
        read(fd, &c, 1);
        write(1, &c, 1);
    }

    close(fd);
    return 0;
}
