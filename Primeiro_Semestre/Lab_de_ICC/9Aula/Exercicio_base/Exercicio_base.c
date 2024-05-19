#include <stdio.h>

#define MAX 100000

void insertionSort(int *vetor, int tamanho);

int main(){
    int sequencia[MAX];
    int tamanho, i;

    scanf("%d", &tamanho);

    for (i = 0; i < tamanho - 1; i++){
        scanf("%d", &sequencia[i]);
    }

    insertionSort(sequencia, tamanho-1);
    
    for (i = 0; i < tamanho; i++){        
        if (i+1 != sequencia[i]){
            printf("Numero desaparecido: %d\n", i+1);
            return 0;
        }
    }
    return 0;
}


void insertionSort(int *vetor, int tamanho){
    int posicaoAtual,temp, i;

    for (i = 0; i < tamanho - 1; i++){
        posicaoAtual = i;
        while (vetor[posicaoAtual] > vetor[posicaoAtual + 1] && posicaoAtual >= 0){
            temp = vetor[posicaoAtual];
            vetor[posicaoAtual] = vetor[posicaoAtual + 1];
            vetor[posicaoAtual + 1] = temp;
            posicaoAtual--;
        }
    }
}