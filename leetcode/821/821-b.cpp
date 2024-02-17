const int ZERO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
       vector<int> ans(s.size(), 1e9);
       int cnt = 1e9; 
       for(int i = 0; i < s.size(); i++){
           if(s[i] == c){
              cnt = 0; 
           } else {
               cnt++;
           }
           ans[i] = cnt;
       } 
       cnt = 1e9;
       for(int i = s.size() - 1; i >= 0; i--){
           if(s[i] == c){
              cnt = 0; 
           } else {
               cnt++;
           }
           ans[i] = min(ans[i], cnt);
       } 
       return move(ans);
    }
};