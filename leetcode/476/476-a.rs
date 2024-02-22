impl Solution {
    pub fn find_complement(mut num: i32) -> i32 {
        let mut ans = 0;
        let mut bit = 0;

        while (num != 0) {
            ans |= ((num & 1) ^ 1) << bit;
            num >>= 1;
            bit += 1;
        }
        ans
    }
}
