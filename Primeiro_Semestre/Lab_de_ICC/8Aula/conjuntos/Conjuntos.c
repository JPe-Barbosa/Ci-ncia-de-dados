#include <stdio.h>

#define MAX 10

int main(){
    int tamA, tamB;
    int a[MAX], b[MAX], entrou1 = 0;

    scanf("%d", &tamA);
    for (int i = 0; i < tamA; i++){
        scanf("%d", &a[i]);
    }
    scanf("%d", &tamB);
    for (int i = 0; i < tamB; i++){
        scanf("%d", &b[i]);
    }

    printf("intersecao: ");
    if (tamA > tamB){
        for (int i = 0; i < tamA; i++){
            for (int j = 0; j < tamB; j++){
                if (a[i] == b[j]){
                    printf("%d ", a[i]);
                    entrou1 = 1;
                }
            }
        }  
    }else{
        for (int i = 0; i < tamB; i++){
            for (int j = 0; j < tamA; j++){
                if (a[j] == b[i]){
                    printf("%d ", b[i]); 
                    entrou1 = 1;
                }
            }
        }
    } 
    if (entrou1 == 0){
        printf("vazio");
    }
    
    printf("\n");
    printf("a - b: ");
    for (int i = 0; i < tamA; i++){
        for (int j = 0; j < tamB; j++){
            if (a[i] == b[j]){
                for (int k = i+1; k < tamA; ++k)  
                    a[k-1] = a[k];
                tamA--;
                i--;
                break;
            }
        }
    }
    if(tamA == 0){
        printf("vazio");
    }else{
        for (int i = 0; i < tamA; i++){
            printf("%d ", a[i]);
        }
    }
    printf("\n");
    return 0;
}