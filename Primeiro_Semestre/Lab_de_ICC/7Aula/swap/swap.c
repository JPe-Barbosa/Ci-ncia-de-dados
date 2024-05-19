#include <stdio.h>

int main(){
    int *ponteiroTemp; 
    int *a; 
    int *b;
    int tempA, tempB;

    a = &tempA;
    b = &tempB;

    scanf("%d %d", a, b); 

    ponteiroTemp = a;
    a = b;
    b = ponteiroTemp;

    printf("%d %d", *a,*b);

}