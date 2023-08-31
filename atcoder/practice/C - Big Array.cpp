#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n, k; cin >> n >> k;

  vector<int> nums(0,0);
  for(int i = 0; i < n; i++){
    int a, b; cin >> a >> b;
    while(b--){
      nums.push_back(a);
    }
  }

  nth_element(nums.begin(),nums.begin() + k - 1, nums.end());
  cout << nums[k-1] << endl;

  return 0;
}
