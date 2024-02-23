impl Solution {
    pub fn majority_element(nums: Vec<i32>) -> i32 {
        let (majority, _) = nums.iter().fold((0, 0), |(mut ans, mut cnt), &num| {
            if cnt == 0 {
                (num, 1)
            } else if ans == num {
                (ans, cnt + 1)
            } else {
                (ans, cnt - 1)
            }
        });
        majority
    }
}
