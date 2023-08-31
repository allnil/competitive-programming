#include <iostream>
#include <queue>

using namespace std;

int main(){
  vector<string> decks(3, "");

  for(int i = 0; i < 3; i++){
    cin >> decks[i];
  }
  
  queue<int> qdecks[3];

  for(int i = 0; i < 3; i++){
    for(auto c : decks[i]){
      int player; 
      if(c == 'a'){
        player = 0;
      } else if(c == 'b'){
        player = 1;
      } else if(c == 'c'){
        player = 2;
      }
      qdecks[i].push(player);
    }
  }
  
  int nextPlayer = 0;
  while(true){
  if(qdecks[nextPlayer].empty()){
     if(nextPlayer == 0){
       cout << "A" << endl;
     } else if(nextPlayer == 1){
       cout << "B" << endl;
     } else if(nextPlayer == 2){
       cout << "C" << endl;
     }
     break;
   }
     int currentCard = qdecks[nextPlayer].front();
   qdecks[nextPlayer].pop();
   nextPlayer = currentCard;
  }
  

  return 0;
}
