#include <stdio.h>
#include <string.h>

int main(){
    char frases[7][41];
    int dia, escolha;

    strcpy(frases[0], "Segunda: Aula de computacao\n");
    strcpy(frases[1], "Terca: Treino de volei\n");
    strcpy(frases[2], "Quarta: Aula de calculo\n");
    strcpy(frases[3], "Quinta: Lista de GA\n");
    strcpy(frases[4], "Sexta: Festa da Sacim\n");
    strcpy(frases[5], "Sabado: Jantar em familia\n");
    strcpy(frases[6], "Domingo: Depressao pos final de semana\n");

    scanf("%d %d", &dia, &escolha);
    if(dia>7 || dia<1){
        printf("Dia nao registrado");
    }else
    {
        if(escolha == 1){
        printf(frases[dia-1]);
        }else{
        for (int i = dia - 1; i < 7; i++)
            printf(frases[i]);
    }
    }
    
    

}
