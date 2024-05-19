#include <stdio.h>
int main(){
    int firstNumber, secondNumber;
    int sum, sub, mult, intDiv;
    float racDiv;

    scanf("%d", &firstNumber);
    scanf("%d", &secondNumber);

    sum = firstNumber + secondNumber;
    sub = firstNumber - secondNumber;
    mult = firstNumber * secondNumber;
    intDiv = firstNumber / secondNumber;
    racDiv = (float)firstNumber / secondNumber;

    printf("Soma: %d\n", sum);
    printf("Subtracao: %d\n", sub);
    printf("Multiplicacao: %d\n", mult);
    printf("Divisao Inteira: %d\n", intDiv);
    printf("Divisao Racional: %0.3f\n", racDiv);

    return 0;
}