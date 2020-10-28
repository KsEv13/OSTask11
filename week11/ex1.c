#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main() {
    int fd;
    struct stat file_stat;
    char * buffer;
    size_t file_size;
    size_t new_len;

    fd = open("ex1.txt", O_RDWR);
    fstat(fd, &file_stat);
    file_size = (size_t) file_stat.st_size;
    buffer = mmap(0, file_size, PROT_WRITE, MAP_SHARED, fd, 0);
    char * to_write = "This is a nice day";
    new_len = strlen(to_write);
    memcpy(buffer, to_write, new_len);
    memset(buffer + new_len, 0, file_size - new_len);
}

