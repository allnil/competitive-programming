#include "stdio.h"
#include <string>


int main() {
    int d;
    char m[3];
    
    std::string ms = m;
    scanf("%s %d", m, &d);
    
    if ((ms.compare("OCT") && d == 31) || (ms.compare("DEC") && d == 25)) {
        printf("yup\n");
    } else {
        printf("nope\n");
    }
    return 0;
}