const int ZERO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
    int cnt;
    bool isPalindrom(string_view s){
        int l = 0; int r = s.size() - 1;
        while(l <= r){
            if(s[l] != s[r]){
                return false;
            }
            l++; r--;
        }
        cnt++;
        return true;
    }
public:
    int countSubstrings(string s) {
       cnt = 0;
       int maxLen = s.size();

       int curLen = 1;

       while(curLen <= maxLen){
           for(int i = 0; i <= s.size() - curLen; i++){
               isPalindrom(s.substr(i, curLen));
           }
           curLen++;
       } 
       return cnt;
    }
};