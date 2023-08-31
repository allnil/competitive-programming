#include <iostream>


using namespace std;


const int ZERO = [](){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

int main(){
  int t; cin >> t;
  while(t--){
   int n; cin >> n;
   string a,s;  
   cin >> a;
   int l = 0;
   int r = 1;
   while(l < n - 1){
     if(a[l] == a[r]){
       s.push_back(a[l]);
       l = r + 1;
       r = r + 2;
     } else {
       r++;
     }
  }
  cout << s << endl;
  }
  return 0;
}

