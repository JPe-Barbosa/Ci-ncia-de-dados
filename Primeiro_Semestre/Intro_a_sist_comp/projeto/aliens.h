#define TAM_CAMP 9

void desceLinha(int Campo[][TAM_CAMP]);
int andaAliens(int Campo[][TAM_CAMP], int ultimoDireita, int tamanhoLinhaAliens, int direita);

//É responsavel pela movimentação dos aliens bem como verificar a condição de vitória
int andaAliens(int Campo[][TAM_CAMP], int ultimoDireita, int tamanhoLinhaAliens, int direita){
    int temp;
    if (ultimoDireita == TAM_CAMP || ultimoDireita == tamanhoLinhaAliens){
        //desce todos uma linha
        desceLinha(Campo);        
    }
    if (!(ultimoDireita == TAM_CAMP || ultimoDireita == tamanhoLinhaAliens)){
        //move todos para direita ou esquerda
    }
     for (int i = TAM_CAMP-2; i >= 0; i--)
    {
        for (int j = TAM_CAMP-1; j >= 0; j--)
        {
            
        }
    }
    return 0;
}

void desceLinha(int Campo[][TAM_CAMP]){
    
    for (int i = TAM_CAMP; i < 1; i--){
        for (int j = 0; j < TAM_CAMP; j++){
            if(Campo[i][j] == 1){
                printf("s");
                Campo[i+1][j] = 1;
                Campo[i][j] = 0;
            }
        }
    }
}