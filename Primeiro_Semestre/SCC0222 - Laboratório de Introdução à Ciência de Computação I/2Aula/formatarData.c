#include <stdio.h>
int main(){
    unsigned int day, month, year;
    scanf("%2u%2u%u", &day, &month, &year );
    printf("%02i/%02i/%i\n", day, month, year);
}