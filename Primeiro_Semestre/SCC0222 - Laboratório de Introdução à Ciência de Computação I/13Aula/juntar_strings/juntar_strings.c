#include <string.h>
#include <stdio.h>

void strcatModificado(char *primeiroVetor, char *segundoVetor, char *interseccao, char *juncao);
int indexInicial(char *vetor, char *inicio);
int indiceFinal(char *vetor, char *parada);
void strcpyModificado(  char *destino, char *origem, int inicioDestino, int inicioOrigem, int fimOrigem);
void removeNewline(char *str);
int main(){
    char A[131] = {0};
    char B[131] = {0};
    char interseccao[21] = {0};
    char juncao[240] = {0};


    fgets(A, 130, stdin);
    fgets(B, 130, stdin);
    fgets(interseccao, 20, stdin);

    removeNewline(A);
    removeNewline(B);
    removeNewline(interseccao);

    strcatModificado(A, B, interseccao,juncao);

    printf("%s\n", juncao);
}

void strcatModificado(char *primeiroVetor, char *segundoVetor, char *interseccao, char *juncao){
    
    int index1 = indiceFinal(primeiroVetor, interseccao);
    int index2 = indexInicial(segundoVetor, interseccao);

    //há +1 e -1 nos parametros abaixo. Isto serve para consumir o espaço que cercam a palavra
    //chave
    strcpyModificado(juncao, primeiroVetor, 0, 0, index1 - 1);
    removeNewline(juncao);  
    //se o primeiro vetor não for vazio deve haver um espaço entre as duas strings
    if(index1 != 0) juncao[index1++] = ' ';

    strcpyModificado(juncao, segundoVetor, index1, index2, strlen(segundoVetor));

    juncao[index1 + strlen(segundoVetor) - index2] = '\0';
}


//retorna o index apos uma string em um vetor
int indexInicial(char *vetor, char *inicio){
    int i,j;
    j = 0;
    for(i = 0; i <= strlen(vetor); i++){
        if(vetor[i] == inicio[j] && j < strlen(inicio)){
            j++;
        }else if(j == strlen(inicio)){
            return i;
        }else{
            j = 0;
        }
    }
    return i;
}
//retorna o index onde começa uma string em um vetor
int indiceFinal(char *vetor, char *parada){
    int i,j,index = 0;
    j=0;
        for(i = 0; i <= strlen(vetor); i++){
        if(vetor[i] == parada[j]){
            j++;
        }else if(j == strlen(parada)){
            return index;
        }else{
            index = i;
            j = 0;
        }
    }
    return index;
}

void strcpyModificado(  char *destino, char *origem, 
                        int inicioDestino, 
                        int inicioOrigem, int fimOrigem){
    int i, tamanho = 0;
    tamanho = fimOrigem - inicioOrigem;
    for(i = 0; i <= tamanho; i++){
        if(origem[inicioOrigem + i] != '\n')destino[inicioDestino + i] = origem[inicioOrigem + i];
    }
    printf("%s", destino);
}

void removeNewline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}