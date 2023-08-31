#include <stdio.h>
#include <string.h>
#include <string>
#include <set>

using namespace std;

int main(){
  char input[203];
  set<string> dict;


  while(scanf("%200s", input) != EOF){
    string word;

    for (int i = 0; i < strlen(input); i++) {
        char c = tolower(input[i]);
        if((c >= 97 && c <= 122)) {   
          word += c;
        } else if (word != ""){
          dict.insert(word);
          word = "";
        }
      }
      if (word != "")
          dict.insert(word);
  }

  for (set<string>::iterator iter = dict.begin(); iter != dict.end(); ++iter){
      string w = *iter;
      printf("%s\n", w.c_str());
  }

  return 0;
}