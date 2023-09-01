class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int min_price = 1e9;
        
        for(int i =0; i < prices.size(); i++){
            min_price = min(min_price, prices[i]);
            int profit = prices[i] - min_price;
            ans = max(ans, profit);
        }

        return ans;
    }
};
