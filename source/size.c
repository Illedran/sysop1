#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: <path_to_file>");
        return 0;
    }
    int o = open(argv[1], O_RDONLY);
    if (o == -1) {
        perror("Error when opening file");
        return 1;
    }
    int size = (int) lseek(o, 0, SEEK_END);
    printf("Size of file: %i\n", size);
    if (close(o) == -1) {
        perror("Error when closing file");
        return 1;
    }
    return 0;
}