#include <stdio.h>

#define MAX 100

int main(){
    float precoCompra[MAX], precoVenda[MAX], quantAdiquirida[MAX], quantVendida[MAX];
    float lucro, maiorLucroProd = 0;
    int quantProdutos = 0, i, indiceMaiorReceita;
    
    scanf("%d", &quantProdutos);

    for(i = 0; i < quantProdutos; i++){
        scanf("%f %f %f %f", &precoCompra[i], &precoVenda[i], &quantAdiquirida[i], &quantVendida[i]);
    }

    for(i = 0; i < quantProdutos; i++){

        lucro += precoVenda[i] * quantVendida[i]  - precoCompra[i]*quantAdiquirida[i];

        if((precoVenda[i] * quantVendida[i]  - precoCompra[i]*quantAdiquirida[i]) > maiorLucroProd){
            indiceMaiorReceita = i;
            maiorLucroProd = precoVenda[i] * quantVendida[i]  - precoCompra[i]*quantAdiquirida[i];
        }
    }
    if(quantProdutos == 0){
        printf("Sem atividades registradas hoje");
    }else{
        if (lucro >= 0){
            printf("lucro: %.2f\n", lucro);
        }else{
            printf("prejuizo: %.2f\n", lucro*(-1));
        }
        if(maiorLucroProd >= 0){
            printf("produto: %d lucro relativo: %.2f", indiceMaiorReceita + 1, maiorLucroProd);
        }else{
            printf("produto: %d prejuizo relativo: %.2f", indiceMaiorReceita + 1, maiorLucroProd);
        }
    }

    return 0;
}