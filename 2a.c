#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    struct stat s;

    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    if (stat(argv[1], &s) < 0) {
        perror("stat");
        return 1;
    }

    printf("Size: %ld\n", s.st_size);
    printf("Links: %ld\n", s.st_nlink);
    printf("UID: %d\n", s.st_uid);
    printf("GID: %d\n", s.st_gid);
    printf("Mode: %o\n", s.st_mode);

    return 0;
}
