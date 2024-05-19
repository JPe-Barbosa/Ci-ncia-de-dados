#include <stdio.h>
#include <stdlib.h>
int main(){
    int quantCorridas;
    float velA,velB, tempo;

    scanf("%d", &quantCorridas);
    for (int i = 0; i < quantCorridas; i++){
        scanf ("%f %f %f", &velA, &velB, &tempo);

        if (tempo == 0 )
        {
            printf("A corrida ainda nao comecou\n");
        }else{
            if (velA == 0 || velB == 0){
                if(velA == 0){
                    if(velB == 0){
                        printf("Os dois pilotos nao querem competir\n");
                    }else{
                        printf("O piloto A desistiu inesperadamente\n");
                    }

                }else{
                    printf("O piloto B desistiu inesperadamente\n");
                }
            }else{
                if(tempo < 0){
                    printf("De alguma forma os pilotos voltaram no tempo\n");
                }else{
                   if(velA == velB){
                        printf("Os karts empataram, percorrendo cada %0.2fkm\n", velA*tempo);
                   }else{
                      if(velA > velB){
                        printf("O kart A venceu e percorreu %0.2fkm a mais que o kart B\n", velA*tempo - velB*tempo);
                      }else{
                        printf("O kart B venceu e percorreu %0.2fkm a mais que o kart A\n", velB*tempo - velA*tempo);
                      }
                   }
                }
            }
        }
    }
    return 0;
}
