#include <stdio.h>
#include <numeric>
#include <iostream>
:wchar_t
using namespace std;

int main(){
 int lala; std::cin >> lala;

 int A,B,C; scanf("%d %d %d", &A, &B, &C);
 puts(C%gcd(A,B)==0?"YES":"NO");
}
