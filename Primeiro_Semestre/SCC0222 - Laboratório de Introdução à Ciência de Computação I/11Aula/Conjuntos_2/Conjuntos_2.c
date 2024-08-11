    #include <stdio.h>
    #include <stdlib.h>

    void imprimeVetor(int *vetor, int tamanho);
    void leVetor(int *vetor, int tamanho);
    void insertionSort(int *vetor, int tamanho);
    int* conjuntoUniao(int* vetor1,int* vetor2, int tamanho1,int tamanho2);
    int* conjuntoSubtracao(int* vetor1,int* vetor2, int tamanho1,int tamanho2);


    int main(){
        int *vetorA, *vetorB,*uniao,*subtracao;
        int tamanhoA,tamanhoB,i;

        //aloca e le
        scanf("%d", &tamanhoA);
        vetorA = malloc(sizeof(int) * tamanhoA);   
        leVetor(vetorA,tamanhoA);
        
        scanf("%d", &tamanhoB);
        vetorB = malloc(sizeof(int) * tamanhoB);   
        leVetor(vetorB, tamanhoB);

        insertionSort(vetorA, tamanhoA);
        insertionSort(vetorB, tamanhoB);

        //imprime conjuntos
        printf("conjunto A:");
        if (tamanhoA != 0){
            imprimeVetor(vetorA,tamanhoA);
        }else{
            printf(" vazio\n");
        }


        printf("conjunto B:");
        if (tamanhoB != 0){
            imprimeVetor(vetorB,tamanhoB);
        }else{
            printf(" vazio\n");
        }

        uniao = conjuntoUniao(vetorA,vetorB,tamanhoA,tamanhoB);
        printf("A uniao B:");
        if(uniao[0] != 0){
            for(i = 1; i <= uniao[0]; i++){
                printf(" %d", uniao[i]);
            }
            printf("\n");
        }else{
            printf(" vazio");
        }

        subtracao = conjuntoSubtracao(vetorA,vetorB,tamanhoA,tamanhoB);
        printf("(A uniao B) - (A interseccao B):");
        if(subtracao[0] != 0){
            for(i = 1; i <= subtracao[0]; i++){
                printf(" %d", subtracao[i]);
            }
            printf("\n");
        }else{
            printf(" vazio");
        }
        
        
    }
    void imprimeVetor(int *vetor, int tamanho){
        int i;
        for (i = 0; i < tamanho; i++){
            printf(" %d", vetor[i]);
        }
        printf("\n");
    }


    void leVetor(int *vetor, int tamanho){
        int i;
        for (i = 0; i < tamanho; i++){
            scanf(" %d", &vetor[i]);
        }
    }
    void insertionSort(int *vetor, int tamanho){
        int posicaoAtual,temp, i;

        for (i = 0; i < tamanho - 1; i++){
            posicaoAtual = i;
            while (vetor[posicaoAtual] > vetor[posicaoAtual + 1] && posicaoAtual >= 0){
                temp = vetor[posicaoAtual];
                vetor[posicaoAtual] = vetor[posicaoAtual + 1];
                vetor[posicaoAtual + 1] = temp;
                posicaoAtual--;
            }
        }
    }

    int* conjuntoUniao(int* vetor1,int* vetor2, int tamanho1,int tamanho2){
        int *vetorUniao;
        int i,j,tamanho;
        int vetortemp[tamanho1+tamanho2];

      

        tamanho = 0;
        i=0;
        j=0;
        while (i < tamanho1 || j < tamanho2){
            if(vetor1[i] > vetor2[j]){
                if(j < tamanho2){
                    if(vetortemp[tamanho-1] != vetor2[j])vetortemp[tamanho++] = vetor2[j];
                    j++;
                }else{
                    if(vetortemp[tamanho-1] != vetor1[i])vetortemp[tamanho++] = vetor1[i];
                    i++;
                }
            }else{
                if(i < tamanho1){
                    if(vetortemp[tamanho-1] != vetor1[i])vetortemp[tamanho++] = vetor1[i];
                    i++;
                }else{
                    if(vetortemp[tamanho-1] != vetor2[j])vetortemp[tamanho++] = vetor2[j];
                    j++;
                }
            }
        }
        vetorUniao = malloc(tamanho * sizeof(int) + 1);
        vetorUniao[0] = tamanho;
        for (i = 0; i < tamanho; i++){
            vetorUniao[i+1] = vetortemp[i];
        }

        return vetorUniao;
    }

    int* conjuntoSubtracao(int* vetor1,int* vetor2, int tamanho1,int tamanho2){
        int *vetorSubtracao;
        int i,j,tamanho;
        int vetortemp[tamanho1+tamanho2];
        int vetortemp1[tamanho1+tamanho2];

        for (i = 0; i < tamanho1; i++){
            vetortemp[i] = vetor1[i];
        }
        for (i = 0; i < tamanho2; i++){
            vetortemp[i+tamanho1] = vetor2[i];
        }
        insertionSort(&vetortemp[0], tamanho1+tamanho2);

        tamanho = 0;
        for (i = 0; i < tamanho1+tamanho2; i++){
            if(vetortemp[i] != vetortemp[i+1] && vetortemp[i] != vetortemp[i-1]){
                vetortemp1[tamanho++] = vetortemp[i];
            }
        }
        vetorSubtracao = malloc(tamanho * sizeof(int)+1);
        vetorSubtracao[0] = tamanho;
        for (i = 0; i < tamanho; i++){
            vetorSubtracao[i+1] = vetortemp1[i];
        }
        return vetorSubtracao;
    }