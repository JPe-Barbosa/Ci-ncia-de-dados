#include <stdio.h>
#include <math.h>

int main(){
    int a,b,i,j,maiorPrimo = 0,menorPrimo = 0;

    scanf("%d %d", &a, &b);

    for (i = a; i <= b; i++)
    {
        for (j = 1; j <= i; j++)
        {
            if(i == j && j != 1){
                if(menorPrimo == 0)
                    menorPrimo = i;
                maiorPrimo = i;
            };
            if(i % j == 0 && j != 1)break;
        }
    }
    if(maiorPrimo == 0 && menorPrimo == 0){
        printf("nenhum primo no intervalo");
    }else{
        printf("menor primo: %d\n", menorPrimo);
        printf("maior primo: %d\n", maiorPrimo);
    }
    return 0;
}