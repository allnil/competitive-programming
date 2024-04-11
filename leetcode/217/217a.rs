use std::collections::HashSet;

impl Solution {
    pub fn contains_duplicate(nums: Vec<i32>) -> bool {
        if nums.len() < 2 {
            return false;
        }
        let mut map = HashSet::new();
        nums.iter().any(|&v| !map.insert(v))
    }
}