const int ZERO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
    bool englishLetter(char c){
        if(c >= 65 && c <= 90){
            return true;
        }
        if(c >= 97 && c <= 122){
            return true;
        }
        if(c >= 48 && c <= 57){
            return true;
        }
        return false;
    }
public:
    bool isPalindrome(string s) {
        if(s.size() <= 1){
            return true;
        }
       int l = 0; int r = s.size() - 1; 

       while(l < r){
           if(!englishLetter(s[l])){
               l++;
               continue;
           }
           if(!englishLetter(s[r])){
               r--;
               continue;
           }
           if(tolower(s[l]) != tolower(s[r])){
               return false;
           }
           l++;r--;
       }
       return true;
    }
};