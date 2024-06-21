use std::collections::HashSet;

impl Solution {
    pub fn find_disappeared_numbers(mut nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        let set: HashSet<i32> = nums.into_iter().collect();
        let res: Vec<i32> = (1..=(n as i32))
            .filter(|&x| !set.contains(&x))
            .collect();
        res
    }
}