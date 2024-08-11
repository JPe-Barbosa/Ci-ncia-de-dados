#include <stdio.h>

int main(){
    int numero;

    scanf("%d", &numero);

    printf("Valor inicial da variavel: %d\n", numero);

    int *ponteiro1;
    ponteiro1 = &numero;

    printf("Valor do ponteiro antes do incremento: %d\n", *ponteiro1);

    *ponteiro1 = *ponteiro1 + 10;

    printf("Valor do ponteiro depois do incremento: %d\n", *ponteiro1);

    int **ponteiro2;
    ponteiro2 = &ponteiro1;

    printf("Valor do ponteiro para ponteiro antes do incremento: %d\n", **ponteiro2);
    
    **ponteiro2 = **ponteiro2 + 10;

    printf("Valor do ponteiro para ponteiro depois da mudanca: %d\n", **ponteiro2);

    printf("Valor final da variavel: %d\n", numero);
}