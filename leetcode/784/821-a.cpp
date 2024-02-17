class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
       int pos = 0;
       vector<int> ans(s.size(), 1e9);
       int cnt = 1;
       for(int i = 0; i < s.size(); i++){
           if(s[i] == c){
                ans[i] = 0;
                cnt = 1;
               for(int l = i - 1; l >= 0; l--){
                   ans[l] = min(cnt, ans[l]);
                   cnt++;
               }
               cnt = 1;
               for(int r = i + 1; r < s.size(); r++){
                   if(s[r] == c){
                       ans[r] = 0;
                       i = r - 1;
                       break;
                   }
                  ans[r] = min(cnt, ans[r]);
                  cnt++; 
               }
           }
       } 
       return move(ans);
    }
};