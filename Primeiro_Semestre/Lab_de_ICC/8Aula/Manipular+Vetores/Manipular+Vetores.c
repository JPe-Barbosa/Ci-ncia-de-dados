#include <stdio.h>
#include <ctype.h>

#define MAXIMO 255

void ordena(int *vetor, int tamanho);

int main(){
    int entrada[MAXIMO];
    int i,a,b, temp, resposta, tamanho = 0;
    char comando;

     // Entrada dos números até receber 1
    do {
        scanf("%d", &resposta);
        if (resposta != 1) {
            entrada[tamanho++] = resposta;
        }
    } while (resposta != 1);

    // Entrada do comando
    scanf(" %c", &comando);

    if (comando == 'a'){
        ordena(entrada, tamanho);
        //imprime em ordem crescente
        printf("vetor ordenado:");
        for(i = 0; i < tamanho; i++){
            printf("%d ", entrada[i]);
        }
        printf("\n");
    }else if (comando == 'b'){
        //imprime apenas os caracteres da sequência de fibonacci
        printf("Numeros de Fibonacci:");
        for(i = 0; i < tamanho; i++){
            a=1;
            b=1;
            while(b < entrada[i]){
                //calcula próximo número da sequência
                temp = a + b;
                a = b;
                b = temp;
            }
            if (b == entrada[i])printf("%d " ,entrada[i]);
        }
        printf("\n");
    }else if (comando == 'c'){
        //imprime os carateres correspondentes em letra maiúscula
        printf("Vetor maiusculo:");
        for(i = 0; i < tamanho; i++){
            comando = toupper((char)entrada[i]);
            printf("%c ",comando);
        }
        printf("\n");
    }else{
        printf("Comando inexistente\n");
    }
}


//selection sort
void ordena(int *vetor, int tamanho){
    int temp, i, j;
    for  (i = 0; i < tamanho - 1; i++){
        for( j = i+1; j < tamanho; j++){
            if(vetor[i] > vetor[j]){
            temp = vetor[i];
            vetor[i] =  vetor[j];
            vetor[j] = temp;
            }
        }
        while (j < tamanho) j++;
    }
}