#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void remove_invasive_word(char *str, const char *word) {
    int space = 0;
    char *pos, *temp;
    size_t len = strlen(word);
    pos = strstr(str, word)-1;
    if (*(strstr(str, word)-1) == ' ' && *(strstr(str, word)+ len) == ' ') {
        temp = pos + len;
        memmove(pos, temp+1, strlen(temp) + 1);
        space = 1;
    }

    while ((pos = strstr(str, word)) != NULL) {
        temp = pos + len;
        memmove(pos, temp, strlen(temp) + 1);
    }

    if (*temp+1 == ' ' && space == 0) {
        memmove(pos, temp+1, strlen(temp) + 1);
        space = 1;

    }

}

void clean_file(const char *invasive_word, const char *input_filename) {
    FILE *input_file = fopen(input_filename, "rb");

    fseek(input_file, 0, SEEK_END);
    long file_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET); 

    char *buffer = (char *)malloc(file_size + 1);

    size_t read_size = fread(buffer, 1, file_size, input_file);


    buffer[file_size] = '\0';

    remove_invasive_word(buffer, invasive_word);

    printf("%s\n", buffer);

    free(buffer);
    fclose(input_file);
}

int main() {
    char input_filename[20];
    char input_word[20];

    scanf(" %s", &input_word);
    scanf(" %s", &input_filename);

    clean_file(input_word, input_filename);

    return 0;
}