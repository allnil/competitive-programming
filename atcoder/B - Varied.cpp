#include <stdio.h>
#include <cstring>
#include <set>

using namespace std;
int main(){
  char s[30]; scanf("%s", s);
  
	set<char>t;
  int i = 0;
	while(s[i] != '\0'){
    t.insert(s[i]);
    i++;
  }
	puts(strlen(s)==t.size()?"yes":"no");
  return 0;
}