#include <stdio.h>
#include <cstring>


#include <map>

using namespace std;

int main(){
  char s[100050];scanf("%s",s);

  map<char, bool> st;
  
  for(int c = 97; c<=122; ++c){
    st.emplace(c, false);
  }

  int i = 0;
  while(s[i] != '\0'){
    st.at(s[i]) = true;
    i++;
  }

  for(int c = 97; c<=122; ++c){
    bool res = st.at(c);
    if(res){
      continue;
    } else {
      printf("%c\n", c);
      return 0;
    }
  }
  printf("None\n");
  return 0;
}