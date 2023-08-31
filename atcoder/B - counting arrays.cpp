#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main() {
  int N;
  cin >> N;
  set<vector<int>> st;
  for(int i = 0; i < N; i++) {
    int L;
    cin >> L;
    vector<int> v(L);
    for (auto& x : v) cin >> x;
    st.insert(v);
  }
  cout << st.size() << "\n";
}