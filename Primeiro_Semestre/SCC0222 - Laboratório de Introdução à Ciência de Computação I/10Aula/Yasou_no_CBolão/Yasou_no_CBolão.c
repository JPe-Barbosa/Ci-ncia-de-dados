#include <stdio.h>
#include <stdlib.h>

void leMatriz(char **matris, int linhas, int colunas);
void imprimeLugaresPossiveis(char **matris, int linhas, int colunas); 
void imprimeMatriz(char **matriz, int linhas, int colunas);   
/*
    As N linhas seguintes contêm M valores que podem ser:
        ->”c” para cosplayer
        ->”f” para fã sem cosplay
        ->”v” para vazio

    O seu programa dever ́a imprimir uma matriz das mesmas dimens ̃oes da matriz de entrada,
    colocando 
        ->”o” nos lugares possíveis de Ze sentar 
        ->”x” onde ele não puder sentar.
    
*/
int main(){
    char **plateia;
    int M,N,i,j;

    scanf("%d %d", &M, &N);

    plateia = malloc(M * sizeof(int*));
    
    for (i = 0; i < M; i++){
        plateia[i] = malloc(N * sizeof(int));
    }
    
    leMatriz(plateia,M,N);
    imprimeLugaresPossiveis(plateia,M,N);
}

void leMatriz(char **matris, int linhas, int colunas){
    int i, j;
    
    for (i = 0; i < linhas; i++){
        for (j = 0; j < colunas; j++){
            scanf(" %c", &matris[i][j]);
        }
    }
}

void imprimeLugaresPossiveis(char **matris, int linhas, int colunas){
    int i,j,k;
    int ehpossivel,ehDiaTriste = 1;
    int matrisOriginal[linhas][colunas];

    for (i = 0; i < linhas; i++){
        for (j = 0; j < colunas; j++){
            matrisOriginal[i][j] = matris[i][j];
        }
        
    }

    for (i = 0; i < linhas; i++){
        for (j = 0; j < colunas; j++){
            ehpossivel = 1;
            for (k = 0; k < linhas; k++){
                if(matrisOriginal[k][j] == 'c'){
                    ehpossivel = 0;
                    goto fim;
                }
            }
            for (k = 0; k < colunas; k++){
                if(matrisOriginal[i][k] == 'c'){
                    ehpossivel = 0;
                    goto fim;
                }
            }
            fim:
            if (ehpossivel && matris[i][j] == 'v'){
                matris[i][j] = 'o';
                ehDiaTriste = 0;

            }else{
                matris[i][j] = 'x';
            }
        }
    }

    if (ehDiaTriste){
        printf("Eh um dia triste para os mono Yasuo\n");
    }else{
        imprimeMatriz(matris, linhas,colunas);
    }
}
void imprimeMatriz(char **matriz, int linhas, int colunas){
    int i, j;
    for (i = 0; i < linhas; i++){
        for (j = 0; j < colunas; j++){
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
}