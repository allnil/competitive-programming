const int ZERO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    string s;
    vector<string> ans;

    void backtrack(int open, int close) {
        if(close < open){
            return;
        }

        if(open == 0 && close == 0){
            ans.push_back(s);
            return;
        }

        if(open > 0){
            s.push_back('(');
            backtrack(open - 1, close);
            s.pop_back();
        }

        if(close > 0){
            s.push_back(')');
            backtrack(open, close - 1);
            s.pop_back();
        }
    }


    vector<string> generateParenthesis(int n) {
        int open = n; int close = n;

        backtrack(open, close);

        return ans;
    }
};