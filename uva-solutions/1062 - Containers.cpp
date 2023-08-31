#include <stdio.h>
#include <string.h>

#include <stack>
#include <string>
#include <vector>

using namespace std;

int main(){
  int r = 0;

  char containers[1100];

  vector<stack<char> > VS; VS.reserve(30);
  
  while(scanf("%s",containers)) {
    if (strcmp(containers,"end") == 0){
      break;
    }

    VS.resize(0);
    VS.push_back(stack<char>());
		VS[0].push(containers[0]);

    for(int i = 1; i < strlen(containers); i++){
      bool found = false;
      for(int j = 0; j < VS.size(); j++){
        if (containers[i] == VS[j].top()) {
          found = true;
          break;
        } 
        if(containers[i] < VS[j].top()) {
          found = true;
          VS[j].push(containers[i]);
          break;
        }
      };
      if (found == false) {
				VS.push_back(stack<char>());
				VS.back().push(containers[i]);
      };
    }
		printf("Case %d: %lu\n", ++r, VS.size());
  }
  return 0;
}