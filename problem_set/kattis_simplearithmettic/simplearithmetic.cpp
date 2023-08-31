#include <stdio.h>

int main() {
    long double a, b, c = 0;
    while(scanf("%Lf %Lf %Lf", &a,&b,&c) != EOF) {
        double d1 = a * b / c;
        printf("%Lf\n", d1);
    }

    return 0;
}