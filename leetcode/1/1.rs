impl Solution {
    pub fn two_sum(mut nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut m: std::collections::HashMap<i32,i32> = std::collections::HashMap::new();
        for(i, &num) in nums.iter().enumerate() {
            let complement = target - num;
            if let Some(&prev_i) = m.get(&complement){
                return vec![prev_i as i32, i as i32];
            }

            m.insert(num, i as i32);
        }
        unreachable!()
    }
}