const int ZERO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 1;
}();

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0){
            return 0;
        }
        int ans = 0;

        int prevMin = prices[0];
        for(auto &v: prices){
            ans = max(ans, v - prevMin);
            prevMin = min(v, prevMin);
        }
        return ans;
    }
};