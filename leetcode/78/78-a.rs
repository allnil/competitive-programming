impl Solution {
    pub fn subsets(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut res: Vec<Vec<i32>> = Vec::new();
        res.push(vec![]);
        nums.into_iter().for_each(|v|{
            let sz = res.len();
            for i in 0..sz {
                res.push(res[i].clone());
                res.last_mut().expect("should be at least one").push(v);
            }
        });
        res
    }
}