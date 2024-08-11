#include <stdio.h>
int main(){
    int number;
    char character;
    scanf("%c %d", &character, &number);
    printf("numero correspondente: %d\n", character);
    printf("caracter correspondente: %c\n", number);
    printf("octal: %o\n", number);
    printf("hexadecimal: %x\n", number);
    return 0;
}