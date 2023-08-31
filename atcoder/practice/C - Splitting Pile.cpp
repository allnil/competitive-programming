#include <climits>
#include <iostream>
#include <vector>
#include <math.h>
#include <climits>

typedef long long ll;

using namespace std;


int main(){
  int n; cin >> n;

  vector<ll> nums(n, 0);

  ll totalSum = 0;
  for(int i = 0; i < n; i++){
    cin >> nums[i];
    totalSum += nums[i];
  }

  ll a = 0; ll b = totalSum;
  ll ans = 10e18;
  for(int i = 0; i < n - 1; i++){
   a += nums[i]; b -= nums[i]; 
   ll delta = abs(a - b);
   ans = min(ans, delta);
  }
  
  cout << ans << endl;


  return 0;
}
