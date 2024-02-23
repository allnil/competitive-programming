impl Solution {
    pub fn missing_number(nums: Vec<i32>) -> i32 {
        let mut ans: i32 = 0;
        let n = nums.len() as i32;
        for i in 0..n + 1 {
            ans += i;
        }
        for i in nums {
            ans -= i;
        }
        ans
    }
}
