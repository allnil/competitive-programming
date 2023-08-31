#include <stdio.h>

int n, a, b;
 
int main() {
    for(;;) {
        scanf("%d", &n);
        if(n == 0) break;
 
        int i = 0, j = 0;
        a = 0, b = 0;
        while(n > 0) {
            if(1 & n) {
                if(j % 2) {
                    b |= 1 << i;
                } else {
                    a |= 1 << i;
                }
                j++;
            }
            i++;
            n = n >> 1;
        }
 
        printf("%d %d\n", a, b);
    }
}
