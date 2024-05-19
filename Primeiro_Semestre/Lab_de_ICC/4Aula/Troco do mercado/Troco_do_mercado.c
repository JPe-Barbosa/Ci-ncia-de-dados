#include <stdio.h>

int main(){
    int change,n200=0,n100=0,n50=0,n25=0,n10=0,n5=0,n2=0,n1=0;

    scanf("%d", &change);

    while (change != 0)
    {
        if(change >= 200)
        {
            change -= 200;
            n200++;
        }
        if(change >= 100 &&  change < 200)
        {
            change -= 100;
            n100++;
        }
        if(change >= 50 &&  change < 100)
        {
            change -= 50;
            n50++;
        }
        if(change >= 20 &&  change < 50)
        {
            change -= 20;
            n25++;
        }
        if(change >= 10 &&  change < 20)
        {
            change -= 10;
            n10++;
        }
        if(change >= 5 &&  change < 10)
        {
            change -= 5;
            n5++;
        }
        if(change >= 2 &&  change < 5)
        {
            change -= 2;
            n2++;
        }
        if(change == 1)
        {
            change -= 1;
            n1++;
        }

    }
    printf("%d nota(s) de R$ 200\n", n200);
    printf("%d nota(s) de R$ 100\n", n100);
    printf("%d nota(s) de R$ 50\n", n50);
    printf("%d nota(s) de R$ 20\n", n25);
    printf("%d nota(s) de R$ 10\n", n10);
    printf("%d nota(s) de R$ 5\n", n5);
    printf("%d nota(s) de R$ 2\n", n2);
    printf("%d moeda(s) de R$ 1\n", n1);

    return 0;
    
}