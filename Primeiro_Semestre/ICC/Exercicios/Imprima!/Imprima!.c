#include <stdio.h>


int main(){
    //calcula o numero maximo que um long long unsigned int suporta
    //long long unsigned int lastNumber = 0, power;
    //for (int i = 0; i < sizeof(long long unsigned int)*8; i++)
    //{
    //    power = 1;
    //    for (int j = 0; j < i; j++)
    //    {
    //        power = power * 2;
    //    }
    //    lastNumber += power;
    //        printf("%d bit(s), maximo eh %llu\n", i+1 ,lastNumber);
    //}

    long long unsigned int numero;
    scanf("%llu", &numero);
    printf("%llu\n", numero);
}