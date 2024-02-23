use rand::distributions::{Distribution, Uniform};
use rand::rngs::StdRng;
use rand::SeedableRng;

impl Solution {
    pub fn majority_element(nums: Vec<i32>) -> i32 {
        let mut rng = StdRng::seed_from_u64(2125);
        let dist = Uniform::from(0..nums.len());

        let need = nums.len() / 2 + 1;
        loop {
            let value = nums[dist.sample(&mut rng)];
            let count = nums.iter().filter(|&&x| x == value).count();

            if count >= need {
                return value;
            }
        }
    }
}
