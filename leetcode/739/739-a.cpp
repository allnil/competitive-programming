const int ZERO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<int> ans(t.size(), 0);
        stack<int> s;
        for(int i = 0; i < t.size(); i++){
            while(!s.empty() && t[i] > t[s.top()]){
                int idx = s.top(); s.pop();
                ans[idx] = (i - idx);
            }

            s.push(i);
        }

        return ans;
    }
};