#include <stdio.h>

#define MAX 26

int main(){ 
    char tabuleiro[MAX][MAX];
    char linhas[MAX];
    int  colunas[MAX], linha;
    int tamanho, i, j, quant;

    scanf("%d", &tamanho);
    getchar();

    for (i = 0; i < tamanho; i++){
        for (j = 0; j < tamanho; j++){
            scanf("%c ", &tabuleiro[i][j]);
        }
    }
    //for (i = 0; i < tamanho; i++){
    //    for (j = 0; j < tamanho; j++){
    //        printf("%c ", tabuleiro[i][j]);
    //    }
    //    printf("\n");
    //}
    
    scanf("%d", &quant);
    for ( i = 0; i < quant; i++){
        scanf("%c", &linhas[i]);
        scanf("%d ",&colunas[i]);
    }

    for ( i = 0 ; i < quant; i++){
        printf("%c %d\n", linhas[i], colunas[i]);   
    }
    for(i = 0; i < quant; i++){
        linha = linhas[i] - 64;
    }
}