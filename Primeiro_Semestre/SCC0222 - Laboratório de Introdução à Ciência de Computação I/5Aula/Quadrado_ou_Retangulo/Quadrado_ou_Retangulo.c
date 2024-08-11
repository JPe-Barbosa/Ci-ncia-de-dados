#include <stdio.h>

int main(){
    int l1,l2,l3,l4;

    scanf("%d %d %d %d", &l1,&l2,&l3,&l4);

    if(l1 == l2 && l1 == l3 && l1 == l4 && l1>0 && l2>0 && l3>0 && l4>0)
    {
        printf("quadrado!\n");
    }else if (((l1 == l2 && l3 == l4)
            ||(l1 == l3 && l2 == l4)
            ||(l1 == l4 && l3 == l2))
            && l1>0 && l2>0 && l3>0 && l4>0)
    {
        printf("retangulo!\n");
    }else{
        printf("nenhum!\n");
    }
}
