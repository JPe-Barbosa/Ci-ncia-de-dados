#include <stdio.h>
#include <string.h>

int main(){
    int decNum;
    char binaryNum[64] = "";

    scanf("%d", &decNum);

    while (decNum != 0)
    {
        if (decNum % 2 == 0)
            strcat(binaryNum, " 0");
        else
            strcat(binaryNum, " 1");
        decNum /= 2;
    }
    strrev(binaryNum);

    printf(binaryNum);

    return 0;
}