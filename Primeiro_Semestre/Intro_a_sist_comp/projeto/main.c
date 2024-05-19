#include <stdio.h>
#include "campo.h"
#include "aliens.h"

int main(){
    int aliesCord[TAM_CAMP*TAM_CAMP];//alterar para quantidade de aliens
    int naveCord[2];
    int tiroCord[2];
    

    //inicializa campo
    inicializaCampo(aliesCord[TAM_CAMP]);
    imprimeCampo(campo);
    printf("\n");
    desceLinha(campo);
    imprimeCampo(campo);
    //onde o jogo começa
    //while (fim != 1)
    //{
    //    
    //}
    
}