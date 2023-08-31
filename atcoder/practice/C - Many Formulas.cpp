#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;


int main(){
  string S; cin >> S;
  long long total = 0;

  for(int mask = 0; mask < (1 <<S.size() - 1) ; mask++){
    long long sum = 0;
    long long current_number = 0;

    for(int i = 0; i < S.size(); i++){
      current_number = current_number * 10 + (S[i] - '0');

      if(mask & (1<<i)){
        sum += current_number;
        current_number = 0;
      }
    }
    sum += current_number;
    total += sum;

  }

  cout << total << endl;
 return 0;
}
