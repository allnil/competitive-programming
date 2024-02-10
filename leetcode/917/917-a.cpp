class Solution {
public:
    bool englishLetter(char c){
        if(c >= 65 && c <= 90) {
            return true;
        }
        if(c >= 97 && c <= 122){
            return true;
        }
        return false;
    }
    string reverseOnlyLetters(string s) {
       int l = 0; int r = s.size() - 1;
       while(l < r){
           if(englishLetter(s[l]) == false){
               l++;
               continue;
           }
           if(englishLetter(s[r]) == false){
               r--;
               continue;
           }
           swap(s[l], s[r]); l++; r--;
       } 
       return s;
    }
};