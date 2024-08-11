#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void contaPalavras(char *word,char *filename){
    int count, quant, sizeWord, internalCounter, i;
    char temp;
    
    sizeWord = strlen(word);
    //transforma wor em minusculo
    for (i = 0; i < sizeWord; i++){
        word[i] = tolower(word[i]);
    }
    
    //abre o arquivo
    FILE *file = fopen(filename, "r");

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET); 

    char *buffer = (char *)malloc(file_size + 1);

    size_t read_size = fread(buffer, 1, file_size, file);

    buffer[file_size] = '\0';


    internalCounter = 0;
    quant = 0;
    for (int i = 0; i < file_size; i++){
        buffer[i] = tolower(buffer[i]);
        if(buffer[i-1] == ' ' || internalCounter != 0){
            if(buffer[i] == word[internalCounter]){
                internalCounter++;
            }else{
                internalCounter = 0;
            }
        }
        

        if (internalCounter == sizeWord){
            internalCounter = 0;
            quant++;
        }
        
    }
        
       
    printf("quantidade: %d\n", quant);
}


int main(){
    char filename[50];
    char word[50];
    scanf("%s", filename);
    scanf("%s", word);

    contaPalavras(word, filename);
}

