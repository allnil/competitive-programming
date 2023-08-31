#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

const int ZERO = [](){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

int main(){
  int N; cin >> N;
  vector<int> nums(N, 0);
  for(int i = 0; i < N; i++){
    cin >> nums[i];
  }


  int minTotalCost = 1e9;
  int totalCost = 0;
  for(int x = -100; x < 101; x++){
    totalCost = 0;
    for(int i = 0; i < N; i++){
     totalCost += pow(abs(nums[i] - x),2); 
    }    
    minTotalCost = min(minTotalCost, totalCost);
  }

  cout << minTotalCost << endl;

  return 0;
}
