#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertionSort(int *vetorPrincipal, int *vetor2, char **vetor3, int tamanho);

int main(){
    int n, i, j;
    int *ip, *codigo;
    char **conteudo;

    scanf("%d", &n);            
    if (n != 0) {
        ip = calloc(n, sizeof(int));
        codigo = calloc(n, sizeof(int));
        conteudo = malloc(n * sizeof(char*));
        for (i = 0; i < n; i++) {
            scanf("%d %d", &ip[i], &codigo[i]);
            conteudo[i] = malloc((codigo[i] + 1) * sizeof(char));
            scanf("%s", conteudo[i]);
        }

        insertionSort(ip, codigo, conteudo, n);

        for (i = 0; i < n; i++) {
            printf("%s %d\n", conteudo[i], codigo[i]);
        }

        for (i = 0; i < n; i++) {
            free(conteudo[i]);
        }
        
        free(conteudo);
        free(ip);
        free(codigo);
    } else {
        printf("Sem produtos a serem cadastrados\n");
    }

    return 0;
}

void insertionSort(int *vetorPrincipal, int *vetor2, char **vetor3, int tamanho) {
    int i, j, temp;
    char *tempChar;

    for (i = 1; i < tamanho; i++) {
        temp = vetorPrincipal[i];
        int tempCodigo = vetor2[i];
        tempChar = vetor3[i];

        j = i - 1;
        while (j >= 0 && vetorPrincipal[j] < temp) {
            vetorPrincipal[j + 1] = vetorPrincipal[j];
            vetor2[j + 1] = vetor2[j];
            vetor3[j + 1] = vetor3[j];
            j--;
        }
        vetorPrincipal[j + 1] = temp;
        vetor2[j + 1] = tempCodigo;
        vetor3[j + 1] = tempChar;
    }
}
