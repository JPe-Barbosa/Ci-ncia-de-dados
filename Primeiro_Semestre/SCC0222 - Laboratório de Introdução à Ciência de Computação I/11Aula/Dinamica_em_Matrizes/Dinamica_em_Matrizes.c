#include <stdio.h>
#include <stdlib.h>

void leMatriz(int** matriz, int tamanho);
void imprimeMatriz(int** matriz, int tamanho);
int raizExata(int radicando);


int main(){
    int **matriz;
    int n, i;

    scanf("%d", &n);
    n = raizExata(n);
    matriz = malloc(n * sizeof(int*));
    for (i = 0; i < n; i++){
        matriz[i] = malloc(n * sizeof(int));
    }

    leMatriz(matriz, n);
    imprimeMatriz(matriz,n);

    for (i = 0; i < n; i++){
        free(matriz[i]); 
    }
    free(matriz);

}
int raizExata(int radicando){
    int raiz = 0;
    while (raiz*raiz < radicando)raiz++;
    return raiz;
}

void leMatriz(int** matriz, int tamanho){
    int i, j;
    for (i = 0; i < tamanho; i++){
        for(j = 0; j< tamanho; j++){
            scanf(" %d", &matriz[i][j]);
        }
    }    
}

void imprimeMatriz(int** matriz, int tamanho){
    int i, j;
    for (i = 0; i < tamanho; i++){
        for(j = 0; j< tamanho; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }    
}