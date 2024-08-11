#include <stdlib.h>
#include <stdio.h>
#include <string.h> 

void R(int *receitasQuant, char ***nomes, int **farinha, int **ovos, int **oleo, int **acucar, int **chocolate);
void C(int *ingredientesEstoque);
void F(int receitasQuant, char **nomes, int *ingredientesEstoque, int *farinha, int *ovos, int *oleo, int *acucar, int *chocolate);

int main() {
    int *ingredientesEstoque;
    int loop = 1, receitasQuant = 0;
    char **nomes = NULL;
    char comando;
    int *farinha = NULL, *ovos = NULL, *oleo = NULL, *acucar = NULL, *chocolate = NULL;
    
    ingredientesEstoque = calloc(5, sizeof(int));

    while (loop) {
        scanf(" %c", &comando);
        switch (comando) {
            case 'R':
                R(&receitasQuant, &nomes, &farinha, &ovos, &oleo, &acucar, &chocolate);
                break;
            case 'C':
                C(ingredientesEstoque);
                break;
            case 'F':
                F(receitasQuant, nomes, ingredientesEstoque, farinha, ovos, oleo, acucar, chocolate);
                break;
            case 'S':
                loop = 0;
                break;
            default:
                printf("Codigo invalido\n");
                break;
        }
    }
    printf("Quantidade no estoque:\n");
    printf("Acucar: %d\n", ingredientesEstoque[3]);
    printf("Chocolate: %d\n", ingredientesEstoque[4]);
    printf("Farinha: %d\n", ingredientesEstoque[0]);
    printf("Oleo: %d\n", ingredientesEstoque[2]);
    printf("Ovos: %d\n", ingredientesEstoque[1]);
    printf("Receitas cadastradas: %d\n", receitasQuant);

    for (int i = 0; i < receitasQuant; i++) {
        free(nomes[i]);
    }
    free(nomes);
    free(farinha);
    free(ovos);
    free(oleo);
    free(acucar);
    free(chocolate);
    free(ingredientesEstoque);

    return 0;
}

void R(int *receitasQuant, char ***nomes, int **farinha, int **ovos, int **oleo, int **acucar, int **chocolate) {
    char nome[21];
    int tempFarinha, tempOvo, tempOleo, tempAcucar, tempChocolate;

    scanf("%20s %d %d %d %d %d", nome, &tempFarinha, &tempOvo, &tempOleo, &tempAcucar, &tempChocolate);

    (*receitasQuant)++;

    *nomes = realloc(*nomes, (*receitasQuant) * sizeof(char*));
    *farinha = realloc(*farinha, (*receitasQuant) * sizeof(int));
    *ovos = realloc(*ovos, (*receitasQuant) * sizeof(int));
    *oleo = realloc(*oleo, (*receitasQuant) * sizeof(int));
    *acucar = realloc(*acucar, (*receitasQuant) * sizeof(int));
    *chocolate = realloc(*chocolate, (*receitasQuant) * sizeof(int));

    if (!*nomes || !*farinha || !*ovos || !*oleo || !*acucar || !*chocolate) {
        printf("Alocação de memória falhou!\n");
        exit(1);
    }

    (*nomes)[*receitasQuant - 1] = malloc((strlen(nome) + 1) * sizeof(char));
    if (!(*nomes)[*receitasQuant - 1]) {
        printf("Alocação de memória falhou!\n");
        exit(1);
    }
    strcpy((*nomes)[*receitasQuant - 1], nome);
    (*farinha)[*receitasQuant - 1] = tempFarinha;
    (*ovos)[*receitasQuant - 1] = tempOvo;
    (*oleo)[*receitasQuant - 1] = tempOleo;
    (*acucar)[*receitasQuant - 1] = tempAcucar;
    (*chocolate)[*receitasQuant - 1] = tempChocolate;
}

void C(int *ingredientesEstoque) {
    int farinha, ovo, oleo, acucar, chocolate;
    scanf("%d %d %d %d %d", &farinha, &ovo, &oleo, &acucar, &chocolate);
    ingredientesEstoque[0] += farinha;
    ingredientesEstoque[1] += ovo;
    ingredientesEstoque[2] += oleo;
    ingredientesEstoque[3] += acucar;
    ingredientesEstoque[4] += chocolate;
}

void F(int receitasQuant, char **nomes, int *ingredientesEstoque, int *farinha, int *ovos, int *oleo, int *acucar, int *chocolate) {
    int indice;
    scanf("%d", &indice);

    if (indice < 0 || indice >= receitasQuant) {
        printf("Receita nao encontrada!\n");
        return;
    }

    if (ingredientesEstoque[0] < farinha[indice] ||
        ingredientesEstoque[1] < ovos[indice] ||
        ingredientesEstoque[2] < oleo[indice] ||
        ingredientesEstoque[3] < acucar[indice] ||
        ingredientesEstoque[4] < chocolate[indice]) {

        //segundo os casos testes do pdf esta é a implementação correta
        if (ingredientesEstoque[0] < farinha[indice]){
            printf("Farinha insuficiente\n");
        }else if (ingredientesEstoque[1] < ovos[indice]){
            printf("Ovos insuficientes\n");
        }else if (ingredientesEstoque[2] < oleo[indice]){
            printf("Oleo insuficiente\n");
        }else if (ingredientesEstoque[3] < acucar[indice]){
            printf("Acucar insuficiente\n");
        }else{
            printf("Chocolate insuficiente\n");
        }
        /*
        //porém, lógicamente, esta estaria correta
        if (ingredientesEstoque[0] < farinha[indice]) printf("Farinha insuficiente\n");
        if (ingredientesEstoque[1] < ovos[indice]) printf("Ovos insuficiente\n");
        if (ingredientesEstoque[2] < oleo[indice]) printf("Oleo insuficiente\n");
        if (ingredientesEstoque[3] < acucar[indice]) printf("Acucar insuficiente\n");
        if (ingredientesEstoque[4] < chocolate[indice]) printf("Chocolate insuficiente\n");
        */
    } else {
        ingredientesEstoque[0] -= farinha[indice];
        ingredientesEstoque[1] -= ovos[indice];
        ingredientesEstoque[2] -= oleo[indice];
        ingredientesEstoque[3] -= acucar[indice];
        ingredientesEstoque[4] -= chocolate[indice];
        printf("%s feita com sucesso!\n", nomes[indice]);
    }
}