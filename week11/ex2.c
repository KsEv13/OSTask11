#include <stdio.h>
#include <unistd.h>

int main() {
    char b[5];
    char * s = "Hello";
    setvbuf(stdin, b, _IOLBF, sizeof b);
    for (int i = 0; i<5; ++i) {
        printf("%c", s[i]);
        sleep(1);
    }
}

