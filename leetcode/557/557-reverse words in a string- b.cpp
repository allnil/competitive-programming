class Solution {
public:
    string reverseWords(string s) {
        int l = 0; int r = 0;
        while(r <= s.size()){
            if(s[r] == ' ' || r >= s.size()){
                int tmp = r + 1;
                r--;
                while(l <= r) {
                    swap(s[r], s[l]);
                    l++; r--;
                }
                l = tmp;
                r = tmp;
            }
            r++;
        }
        return s;
    }
};