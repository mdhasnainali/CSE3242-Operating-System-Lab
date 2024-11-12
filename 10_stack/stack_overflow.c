#include <string.h>
#include <stdio.h>

void f1(char *str) {
    char buffer[6]; 
    strcpy(buffer, str);
    printf("%s\n", buffer);
}

void main(int argc, char *argv[]) {
    f1(argv[1]);
}