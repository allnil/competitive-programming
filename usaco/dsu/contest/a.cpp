#include <iostream>
#include <vector>


using namespace std;

int main() {
  int t; cin >> t;
  
  while(t--){
    int n; cin >> n;
    vector<int> a(n);
    vector< vector<int> > prefixes(n);
    for(int i = 0; i < n; i++){
      cin >> a[i];
    }

    for(int i = 0; i < a.size(); i++){
      vector<int> prefix;
      for(int j = 0; j <= i; j++){
        prefix.push_back(a[j]);
      }
      prefix.push_back(prefix);
    }

    for(int i = 0; i < prefixes.size(); i++){
      int gcd = prefixes[i][0];
      for(int i = 1; i < prefixes[i].size(); i++){
        gcd = __gcd(gcd, nums[i]);
      }
      
    }

    
  }


  return 0;
}

