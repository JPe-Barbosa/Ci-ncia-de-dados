#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verificaLivro(int tamanho, char **anos, char **titulos, char **autores, char *ano, char *titulo, char *autor);

int main(){
    int n, i, quantidade = 0, indice;
    char **titulos,**autores, **anos; 
    int *livros;
    char *tempTitulo, *tempAutor,*tempAno;

    scanf("%d", &n);

    tempTitulo = malloc(100 * sizeof(char));
    tempAutor = malloc(100 * sizeof(char));
    tempAno = malloc(4* sizeof(char));

    for (i = 0; i < n; i++)
    {
        scanf(" %[^,], %[^,], %[^\n]", tempTitulo, tempAutor, tempAno); 
        indice = verificaLivro(quantidade, anos,titulos,autores,tempAno,tempTitulo,tempAutor);
        if(indice == -1){
            if(quantidade != 0){
                quantidade++;
                titulos = realloc(titulos, quantidade*sizeof(char*));
                autores = realloc(autores, quantidade*sizeof(char*));
                anos = realloc(anos, quantidade*sizeof(char*));
                livros = realloc(livros, quantidade*sizeof(int));
            }else{
                quantidade++;
                titulos = malloc(1 * sizeof(char*));
                autores = malloc(1 * sizeof(char*));
                anos = malloc(sizeof(char*));
                livros = malloc(sizeof(int));
            }

            titulos[quantidade-1] = malloc(strlen(tempTitulo) * sizeof(char));
            autores[quantidade-1] = malloc(strlen(tempAutor) * sizeof(char));
            anos[quantidade-1] = malloc(strlen(tempAno) * sizeof(char));

            strcpy(titulos[quantidade-1], tempTitulo);
            strcpy(autores[quantidade-1], tempAutor);
            strcpy(anos[quantidade-1], tempAno);
            livros[quantidade-1] = 1; 


        }else{
            livros[indice]++;
        }

    }
    free(tempTitulo);
    free(tempAutor);
    free(tempAno);
    
    printf("Catalogo de livros:\n");
    for (i = 0; i < quantidade; i++)
    {
        printf("Livro %d:\n", i+1);
        printf("Titulo: %s\n", titulos[i]);
        printf("Autor: %s\n", autores[i]);
        printf("Ano: %s\n", anos[i]);
        printf("Quantidade: %d\n\n", livros[i]);
    }
    

    for ( i = 0; i < quantidade; i++){
        free(anos[i]);
        free(titulos[i]);
        free(autores[i]);
    }
    free(anos);
    free(titulos);
    free(autores);
    free(livros);
    

}


//retorna o indice se se existe e -1 caso não exista;
int verificaLivro(int tamanho, 
                    char **anos, char **titulos, char **autores, 
                    char *ano, char *titulo, char *autor){
    int i = 0;
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(titulos[i], titulo) == 0 && strcmp(autores[i], autor) == 0 && strcmp(anos[i], ano) == 0) {
            return i;
        }
    }
    return -1;
    
}