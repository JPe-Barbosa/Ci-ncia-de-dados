#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void leMatriz(int **matris, int tamanho);
bool ehDiagonal(int **matriz, int tamanho);
void multiplicaMatriz(int **matriz1,int **matriz2, int tam1, int tam2);
void imprimeMatriz(int **matriz, int tamanho);


int main(){
    int **matrizM, **matrizN;
    int M,N, i, j;
    
    scanf("%d %d", &M,&N);

    //Declara o vetor para vetores, que representam a linha.
    matrizM = malloc(M * sizeof(int*));

    //instancia inteiros segundo a quantidade de colunas e armazena a referencia do 
    //primeiro int da linha no vetor. 
    for(i =0; i < M; i++){
        matrizM[i] = malloc(M * sizeof(int));
    }


    matrizN = malloc(N * sizeof(int*));

    for(i =0; i < N; i++){
        matrizN[i] = malloc(N * sizeof(int));
    }


    leMatriz(matrizM, M);
    leMatriz(matrizN, N);

    printf("Matrizes:\n");
    imprimeMatriz(matrizM,M);
    imprimeMatriz(matrizN,N);

    if(ehDiagonal(matrizM, M)){
        printf("A matriz 1 eh diagonal\n");
    }else{
        printf("A matriz 1 nao eh diagonal\n");
    }
    if(ehDiagonal(matrizN, N)){
        printf("A matriz 2 eh diagonal\n");
    }else{
        printf("A matriz 2 nao eh diagonal\n");
    }

    multiplicaMatriz(matrizM,matrizN,M,N);
    
}

void leMatriz(int **matris, int tamanho){
    int i, j;
    
    for (i = 0; i < tamanho; i++){
        for (j = 0; j < tamanho; j++){
            scanf("%d", &matris[i][j]);
        }
    }
}

bool ehDiagonal(int **matriz, int tamanho){
    int i,j;

    for(i = 0; i < tamanho; i++){
        for (j = 0; j < tamanho; j++){
            if(matriz[i][j] != 0 && i != j){
                return false;
            }
        }
    }
    return true;
}

void multiplicaMatriz(int **matriz1,int **matriz2, int tam1, int tam2){
    if(tam1 == tam2){
        int i,j,k, soma;
        printf("Matriz multiplicada:\n");
        for(i = 0; i < tam1; i++){
            for(j = 0; j < tam1; j++){
                soma = 0;
                for (k= 0; k < tam1; k++)soma= soma + matriz1[i][k]*matriz2[k][j];
                printf("%d ", soma);
            } 
            printf("\n");
        }    
    }else{
        printf("Matrizes de tamanho incompativel");
    }
}

void imprimeMatriz(int **matriz, int tamanho){
    int i, j;
    for (i = 0; i < tamanho; i++){
        for (j = 0; j < tamanho; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}
