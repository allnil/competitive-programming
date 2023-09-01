class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxNext = INT_MIN;
        int ans = 0;

        for(size_t i = prices.size(); i-- > 0;){
            maxNext = max(maxNext, prices[i]);
            ans = max(ans, maxNext - prices[i]);
        }

        return ans;
    }
};