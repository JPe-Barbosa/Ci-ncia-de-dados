#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char *nome;
    char *cpf;
    int idade;
    float saldo;
    float credito;
}pessoa;

int main(){
    int n,i,j,haEndividados;
    char tempNome[21] ={0};
    char tempCPF[12] = {0};
    pessoa *pessoas;

    scanf("%d", &n);
    pessoas = calloc(n, sizeof(pessoa));
    for(i = 0; i < n; i++){
        scanf(" %20[^,], %11[^,], %d, %f, %f", tempNome, 
                                                 tempCPF,
                                                 &pessoas[i].idade, 
                                                 &pessoas[i].saldo, 
                                                 &pessoas[i].credito);
        pessoas[i].nome = malloc((strlen(tempNome) + 1) * sizeof(char));
        pessoas[i].cpf = malloc((strlen(tempCPF) + 1) * sizeof(char));
        strcpy(pessoas[i].nome, tempNome);
        strcpy(pessoas[i].cpf, tempCPF);
        
        for(j = 0; j < 21; j++){
            tempNome[i] = 0;
        }
        for(j = 0; j < 12; j++){
            tempCPF[i] = 0;
        }
    }

    for(i = 0; i < n; i++){
        printf("Dados da pessoa %d:\n", i+1);
        printf("Nome: %s\n", pessoas[i].nome);
        printf("CPF: %s\n", pessoas[i].cpf);
        printf("Idade: %d\n", pessoas[i].idade);
        printf("Saldo: %0.2f\n", pessoas[i].saldo);
        printf("Credito: %0.2f\n\n", pessoas[i].credito);
    }

    haEndividados = 0;
    printf("Pessoas endividadas:\n");
    for(i = 0; i < n; i++){
        if(haEndividados != 0 && pessoas[i].credito > pessoas[i].saldo)printf("\n\n");
        if(pessoas[i].credito > pessoas[i].saldo){
            haEndividados = 1;
            printf("Nome: %s\n", pessoas[i].nome);
            printf("CPF: %s\n", pessoas[i].cpf);
            printf("Divida: %0.2f", pessoas[i].credito - pessoas[i].saldo);
        }
    }
    if(haEndividados == 0){
        printf("Nenhuma pessoa endividada encontrada.");
    }

    for (i = 0; i < n; i++) {
        free(pessoas[i].nome);
        free(pessoas[i].cpf);
    }
    free(pessoas);

    return 0;
}