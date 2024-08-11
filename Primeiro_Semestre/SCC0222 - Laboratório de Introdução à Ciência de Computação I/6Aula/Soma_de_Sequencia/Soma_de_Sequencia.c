#include <stdio.h>

#define LIMITE 1001

int main(){
    int entrada;
    float resultado = 0;

    do 
    {
        scanf("%d", &entrada);
    }while (0 > entrada || entrada > LIMITE);
    

    if(entrada > 0 ){
        for (int i = 1; i <= entrada; i++)
        {
            if(i % 2 == 0)
            {
                resultado -= (float)1/i;
            }else{
                resultado += (float)1/i;
            }
            
        }
    }

    printf("%0.4f", resultado);
    return 0;
}