#include <stdio.h>
#include <math.h>

int main(void) {
    int primeirosDig, segundosDig, i;

    for (i = 1000; i < 10000; i++)
    {
        primeirosDig = i / 100;
        segundosDig =  i % 100;

        if(sqrt(i) == primeirosDig + segundosDig)
            printf("%d\n", i);
    }
    
    


     
}
