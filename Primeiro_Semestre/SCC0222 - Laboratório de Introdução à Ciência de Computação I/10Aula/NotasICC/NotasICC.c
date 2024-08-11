#include <stdio.h>

void insertionSort(float *vetor, int tamanho);

int main(){ 
    float alunosExercicios[100][25];
    float medias[100];
    int quantAlunos, quantAtividades,i,j;

    scanf("%d %d", &quantAlunos, &quantAtividades);
    for(i = 0; i < quantAlunos; i++)
        for(j = 0; j < quantAtividades; j++)
            scanf("%f", &alunosExercicios[i][j]);
    
    for(i = 0; i < quantAlunos; i++){
        for(j = 0; j < quantAtividades; j++){
            medias[i] += alunosExercicios[i][j];
        }    
         medias[i] /= quantAtividades;
    }

    for(i = 0; i < quantAlunos; i++){
        printf("Media do aluno %d = %0.2f : ", i+1, medias[i]);
        if(medias[i] < 5){
            printf("Reprovado\n");
        }else{
            printf("Aprovado\n");
        }
    }

    printf("\n");
    for(i = 0; i < quantAtividades; i++){
        medias[i] = 0;
        for(j = 0; j < quantAlunos; j++){
            medias[i] += alunosExercicios[j][i];
        }    
         medias[i] /= quantAlunos;
    }
    insertionSort(medias, quantAtividades);

    for (i = 0; i < quantAtividades; i++) printf("%0.2f ", medias[i]);
    printf("\n");
    return 0;
}

void insertionSort(float *vetor, int tamanho){
    float temp;
    int posicaoAtual, i;

    for (i = 0; i < tamanho - 1; i++){
        posicaoAtual = i;
        while (vetor[posicaoAtual] < vetor[posicaoAtual + 1] && posicaoAtual >= 0){
            temp = vetor[posicaoAtual];
            vetor[posicaoAtual] = vetor[posicaoAtual + 1];
            vetor[posicaoAtual + 1] = temp;
            posicaoAtual--;
        }
    }
}