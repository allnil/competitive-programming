class Solution {
public:
    void backtracking(vector<string>& ans, const string& s, int pos, string cur){
        if(pos >= s.size()){
            ans.push_back(cur);
            return;
        }
        
        if(s[pos] >= 'a' && s[pos] <= 'z'){
            char ch = toupper(s[pos]);
            backtracking(ans, s, pos + 1, cur + ch);
        } else if(s[pos] >= 'A' && s[pos] <= 'Z') {
            char ch = tolower(s[pos]);
            backtracking(ans, s, pos + 1, cur + ch);
        }
        backtracking(ans, s, pos + 1, cur + s[pos]);
        return;
    }

// 1. Go through the string
// 2. If there is a 'a-z' - toUpper if 'A - Z' toLower
// 3.
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        backtracking(ans, s, 0, "");
        return ans;
    }
};