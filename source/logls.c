#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main() {

    if (fork() == 0) {
        int fd = open("logls.txt", O_CREAT, 0644);
        if (fd == -1) {
            perror("logls: Error when creating file");
            return 1;
        };
        dup2(fd, 1);
    };
    execlp("ls", "ls", "-al", NULL);
    return 0;
}