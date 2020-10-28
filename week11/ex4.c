#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>

int main() {
    int fd1 = open("ex1.txt", O_RDWR);
    char *in_buffer;
    char *out_buffer;
    struct stat file_stat;
    fstat(fd1, &file_stat);
    size_t file_size = (size_t) file_stat.st_size;
    in_buffer = mmap(0, file_size, PROT_READ, MAP_SHARED, fd1, 0);
    int fd2 = open("ex1.memcpy.txt", O_RDWR);
    ftruncate(fd2, file_size);
    fsync(fd2);
    out_buffer = mmap(0, file_size, PROT_WRITE, MAP_SHARED, fd2, 0);
    memcpy(out_buffer, in_buffer, file_size);
}
