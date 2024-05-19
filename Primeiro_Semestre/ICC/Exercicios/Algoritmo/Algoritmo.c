#include <stdio.h>

int main(){
    int numero;
    char nome1, nome2, caractere;

    scanf("%d", &numero);
    getc(stdin);
    scanf("%c", &nome1);
    getc(stdin);
    scanf("%c", &nome2);
    getc(stdin);
    scanf("%c", &caractere);

    int resposta;
    resposta = numero;

    printf("a resposta eh %d", resposta);
    
}