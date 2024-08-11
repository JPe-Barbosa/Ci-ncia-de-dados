#include <stdio.h>

#define MAX 100

void BubbleSort(int vetor[], int tamanho);

int main(){
    int atletas[MAX], posicoes[MAX];
    int quant,i,j,colocacao;

    scanf("%d", &quant);

    for (i = 0; i < quant; i++){
        scanf("%d", &atletas[i]);
        posicoes[i] = atletas[i];
    }

    BubbleSort(posicoes, quant);

    for (i = 0; i < quant; i++){
        printf("%dº Atleta, %d Pontos, ", i+1, atletas[i]);
        j = 0;
        colocacao = 1;
        while(atletas[i] != posicoes[j]){
            j++;
            if (posicoes[j] < posicoes[j - 1]) colocacao++;
        }
        printf("%dº Colocado\n", colocacao);
        
    }
    return 0;
}


void BubbleSort(int vetor[], int tamanho){
	int aux, i, j;
	for(j=tamanho-1; j>=1; j--){
		for(i=0; i<j; i++){
			if(vetor[i]<vetor[i+1]){
				aux=vetor[i];
                    vetor[i]=vetor[i+1];
                    vetor[i+1]=aux;
            }
        }
    }
}