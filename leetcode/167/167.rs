impl Solution {
    pub fn two_sum(numbers: Vec<i32>, target: i32) -> Vec<i32> {
        if numbers.len() < 3 {
            return vec![1,2]
        }

        let mut l = 0;
        let mut r = numbers.len() - 1;

        while(l < r){
            let sum = numbers[l] + numbers[r];
            if sum > target {
                r -= 1;
            } else if sum < target {
                l += 1;
            } else {
                return vec![l as i32 +1 , r as i32+1]
            }
        }

        Vec::default()
    }
}