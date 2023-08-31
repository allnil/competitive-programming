#include "stdio.h"
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
 const int N = 110;
 int n;
 string a[N], b[N];
 map<string, int> cnt;
 scanf("%d", &n);
 for(int i = 0; i < n; i++){
   cin>>a[i]>>b[i];
   cnt[a[i]]++;
   cnt[b[i]]++;
 }
 for(int i = 0; i < n; i++){
   if(a[i]==b[i]){
     if (cnt[a[i]]>2){puts("No");return 0; }
   } else {
     if (cnt[a[i]]>1&&cnt[b[i]]>1) { puts("No"); return 0;}
   }
 }
 puts("Yes");

 return 0;
}
