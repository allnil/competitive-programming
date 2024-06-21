impl Solution {
    pub fn find_disappeared_numbers(mut nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();

        for i in 0..n {
            while nums[i] != (i + 1) as i32 {
                let j = nums[i] as usize - 1;
                if nums[j] == nums[i] {
                    break;
                }
                nums.swap(i, j);
            }
        }

        (1..=n as i32)
            .filter(|&i| nums[(i - 1) as usize] != i)
            .collect()
    }
}