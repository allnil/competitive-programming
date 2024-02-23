impl Solution {
    pub fn majority_element(nums: Vec<i32>) -> i32 {
        let mut ans = 0 as i32;
        let mut cnt = 0 as i32;
        ans = nums[0];
        cnt = 1;
        for i in 1..nums.len() {
            if cnt == 0 {
                ans = nums[i];
            }
            if ans == nums[i] {
                cnt += 1;
                continue;
            }
            cnt -= 1;
        }
        ans
    }
}
