#include <stdio.h>

// I = 1
// V = 5
// X = 10
// L = 50
// C = 100
// D = 500
// M = 1000


#include <stdio.h>

// Função para converter um número inteiro para algarismo romano
void inteiroParaRomano(int numero) {
    // Arrays para armazenar os algarismos romanos e seus valores equivalentes
    char *romanos[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int valores[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    for (int i = 0; i < 13; i++) {
        while (numero >= valores[i]) {
            printf("%s", romanos[i]);
            numero -= valores[i];
        }
    }
}

int main() {
    int tamanho, numero;

    // Entrada do tamanho do vetor
    scanf("%d", &tamanho);

    // Iteração sobre os números
    for (int i = 0; i < tamanho; i++) {
        // Entrada do número
        scanf("%d", &numero);
        // Converte e imprime o número em algarismo romano
        inteiroParaRomano(numero);
        printf("\n");
    }

    return 0;
}