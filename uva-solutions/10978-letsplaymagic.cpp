#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

int main() {
  int n = 0;
  while(scanf("%d", &n)){
    char card[22];
    char word[22];
    int curIdx = -1;

    if (n == 0) { break; }
    vector<string> deck(n);

    for(int i = 0; i < n; ++i) {
      scanf("%s %s", card, word);
      string sword = word;
      int len = sword.length();

      while (len) {
        curIdx = (curIdx + 1)%n;
        if(deck[curIdx]=="")
          --len;
      }
      deck[curIdx] = card;
    }

    printf("%s", deck[0].c_str());
    for (int i = 1; i < deck.size(); i++) {
      printf(" %s", deck[i].c_str());
    }
    printf("\n");
  }


  return 0;
}
