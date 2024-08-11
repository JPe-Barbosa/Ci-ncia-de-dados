#include <stdio.h>

int main(){
    int n1,n2;

    scanf("%d %d", &n1, &n2);

    if ((n1 > n2 && ((n1 - n2) / 3) * 3 == (n1 - n2)) || 
        (n2 > n1 && (n1 + n2) > 400) || 
        (n1 == n2 && ((n1) / 2) * 2 != (n1)) )
    {
        printf("%d", n1+n2);
    }else{
        printf("Nenhuma condicao foi satisfeita");
    }
    
    return 0;
}