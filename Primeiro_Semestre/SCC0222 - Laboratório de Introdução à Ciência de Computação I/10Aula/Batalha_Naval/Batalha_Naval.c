#include <stdio.h>
#include <stdlib.h>

#define MAX 26


void leMatriz(char **matriz, int tamanho){
    int i, j;
    
    for (i = 0; i < tamanho; i++){
        for (j = 0; j < tamanho; j++){
            scanf(" %c", &matriz[i][j]);
        }
    }
}

void imprimeMatriz(char **matriz, int tamanho){
    int i, j;
    for (i = 0; i < tamanho; i++){
        for (j = 0; j < tamanho; j++){
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main(){ 
    char **tabuleiro;
    char linhas[1000];
    int  colunas[1000], linha;
    int tamanho, i, j, quant;

    scanf("%d", &tamanho);

    //alocando a matriz dinamicamente
    tabuleiro = malloc(tamanho * sizeof(char*));
    for (i = 0; i < tamanho; i++){
        tabuleiro[i] = malloc(sizeof(char) * tamanho);
    }

    leMatriz(tabuleiro, tamanho);
    
    scanf("%d", &quant);

    for ( i = 0; i < quant; i++){
        //O espaço antes é importante visto que ele absorve o caractere white space vindo do
        // quant e os subsequentes de cada iteração
        scanf(" %c%d", &linhas[i], &colunas[i]);
    }

    for(i = 0; i < quant; i++){
        //faz um castig para inteiro de tal forma que 'A' representa 0 
        //e a sequencia vai evoluindo progressivamente com cada proxima 
        //letra representando um proximo número
        linha = linhas[i] - 'A';

        //A notação para uma matriz dinamicamente alocada neste caso é a mesma
        //para uma não. "colunas" precisa decrementar um pois o usuário começa a
        //contar o tabuleiro em 1
        if(tabuleiro[linha][colunas[i]-1] == 'N'){
            printf("acerto!\n");
            tabuleiro[linha][colunas[i]-1] = 'X';
        }else{
            printf("erro!\n");
        }
    }

    imprimeMatriz(tabuleiro, tamanho);
}