impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        if prices.is_empty() {
            return 0
        }
        let mut ans: i32 = 0;
        let mut prev_min = prices[0];
        prices.into_iter().for_each(|v|{
            ans = ans.max(v - prev_min);
            prev_min = prev_min.min(v);
        });

        ans
    }
}