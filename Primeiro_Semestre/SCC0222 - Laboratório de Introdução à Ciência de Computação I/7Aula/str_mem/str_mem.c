#include <stdio.h>

int main() {
    // Declarando uma string com espaço para 26 caracteres + 1 para o caractere nulo
    char str[27];
    
    // Lendo a string da entrada padrão
    fgets(str, sizeof(str), stdin);
    
    // Ponteiro para percorrer a string
    char *ptr = str;
    
    // Loop para imprimir caractere por caractere
    while (*ptr != '\0') {
        printf("%c\n", *ptr);
        ptr++; // Movendo o ponteiro para o próximo caractere
    }
    
    return 0;
}
