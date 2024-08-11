#include <math.h>
#include <stdio.h>

#define PI 3.14159265358979323846

int main(){
    int sides;
    double length, area;

    scanf("%d %lf", &sides, &length);
    area = sides * length*length / (tan(PI/sides) * 4);
    printf("%lf", area);
    return 0;
}