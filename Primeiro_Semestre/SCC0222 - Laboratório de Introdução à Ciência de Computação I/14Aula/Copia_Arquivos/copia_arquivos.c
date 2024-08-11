#include <stdio.h>
#include <stdlib.h>

void clonaPrinta(const char *filename) {
    FILE *file = fopen(filename, "rb");

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET); 

    char *buffer = (char *)malloc(file_size + 1);

    size_t read_size = fread(buffer, 1, file_size, file);

    buffer[file_size] = '\0';

    printf("%s\n", buffer);

    free(buffer);
    fclose(file);
}

int main(){
    char filename[50];
    scanf("%s", filename);

    clonaPrinta(filename);

    return 0;
}