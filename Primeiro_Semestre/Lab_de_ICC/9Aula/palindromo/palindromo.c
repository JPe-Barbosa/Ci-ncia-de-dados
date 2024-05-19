#include <stdio.h>
#include <string.h>

#define MAX 100

int main(){
    char palavras[MAX][MAX];
    int quantPalavras, i,j,k, fim, ehPalidromo = 1;

    scanf("%d", &quantPalavras);

    for(i = 0; i < quantPalavras; i++){
       scanf("%s", palavras[i]);
       //fgets(palavras[i], 100, stdin);
    }

    for (i = 0; i < quantPalavras; i++){
        fim = 0;
        while (palavras[i][fim] != '\0' && palavras[i][fim] != '\n'){
            fim++;
        }
        k = fim-1;
        for (j = 0; j < fim/2; j++){
            if (palavras[i][j] != palavras[i][k]){
                ehPalidromo = 0;
            }
            k--;
        }

        if(ehPalidromo && fim > 2){
            printf("%s eh um palindromo\n", palavras[i]);
        }else{
            printf("%s nao eh um palindromo\n", palavras[i]);
            ehPalidromo = 1;
        }
        
        
    }

}