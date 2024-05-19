#include <stdio.h>

int main(){
    int unsigned lado1, lado2, lado3;
    printf("insira o valor dos lados de um triangulo com espacos: ");
    scanf("%u %u %u", &lado1, &lado2, &lado3);

    if (lado1 == 0 || lado2 == 0 || lado3 == 0){
        printf("nao forma um triangulo");
    }else{
        if(((lado1 + lado2) <= lado3) || ((lado2 + lado3) <= lado1) ||  ((lado3 +lado1) <= lado2)){
            printf("nao forma um triangulo");
        }else{
            if( (lado1 == lado2) && (lado1 == lado2) && (lado3 == lado2)){
                printf("forma um triangulo equilatero");
            }else if ((lado1 == lado2) || (lado1 == lado2) || (lado3 == lado2)){
                printf("forma um triangulo isoceles");
            }else{
                printf("forma um triangulo escaleno");
            }
        }
    }
   
    return 0;
}