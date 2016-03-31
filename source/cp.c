#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>

const uint16_t BUFF_SIZE = 64;

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: <source_file> <destination_file>");
        return 0;
    }
    int src = open(argv[1], O_RDONLY);
    int dst = open(argv[2], O_CREAT | O_EXCL, 0700);
    if (src == -1) {
        perror("cp: error when opening file");
        return 1;
    }
    void *buffer = malloc(BUFF_SIZE);
    while (read(src, buffer, sizeof(buffer)) != 0) {
        if (write(dst, buffer, sizeof(buffer)) == -1) {
            perror("cp: error when writing");
            return 1;
        };
    }
    if (close(src) == -1 || close(dst) == -1) {
        perror("cp: error when closing file");
        return 1;
    }
    free(buffer);
    return 0;
}