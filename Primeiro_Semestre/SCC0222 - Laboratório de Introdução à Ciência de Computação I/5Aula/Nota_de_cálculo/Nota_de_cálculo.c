#include <stdio.h>

int main(){
    float p1,p2,l1,l2,l3,l4,medlist, medfi;

    scanf("%f %f %f %f %f %f", &p1,&p2,&l1,&l2,&l3,&l4);

    medlist = (l1+l2+l3+l4)/4;

    medfi = (p1+ p2 + medlist)/3;

    if (medfi >= 5 && medlist != 0)
    {
        printf("Aprovado\n");
    }else if (medfi >=3 && medlist != 0)
    {
        printf("Recuperacao\n");
    }else{
        printf("Reprovado\n");
    }
    return 0;
}