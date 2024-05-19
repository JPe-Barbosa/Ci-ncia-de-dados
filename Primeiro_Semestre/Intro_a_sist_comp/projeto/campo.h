#include <stdio.h>

#define TAM_CAMP 9
#define MARGEM_LATERAL 3
#define MARGEM_INFERIOR 4

//O campo é ditado pelas coordenas do tiro dos aliens e da nave.
//Nos vetores a componente par representa o eixo y (linha) e 
//a coordenada impar o eixo x (coluna)

void inicializaCampo(int aliesCord[TAM_CAMP],int naveCord[2],int tiroCord[2]);

void imprimeCampo(int aliesCord[TAM_CAMP],int naveCord[2],int tiroCord[2]);

void inicializaCampo(int aliesCord[TAM_CAMP],int naveCord[2],int tiroCord[2]){
    int k = 0;
    for (int i = 0; i < TAM_CAMP; i++) 
    {
        for (int j = 0; j < TAM_CAMP; j++) 
        {
            if(j >= MARGEM_LATERAL && j < TAM_CAMP - MARGEM_LATERAL && i < TAM_CAMP - MARGEM_INFERIOR){
                aliesCord[k] = i;
                aliesCord[k+1] = j;
            }
        }
    }
    naveCord[0] = TAM_CAMP - 1;
    naveCord[1] = TAM_CAMP/2;
}

void imprimeCampo(int aliesCord[TAM_CAMP],int naveCord[2],int tiroCord[2]){
     for (int i = 0; i < TAM_CAMP; i++)
    {
        for (int j = 0; j < TAM_CAMP; j++)
        {
            if()
        }
        printf("\n");
    }
}