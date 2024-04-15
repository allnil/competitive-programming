impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        if s.len() != t.len() {
            return false
        }
        let mut m = std::collections::HashMap::new();
        let mut anagram = true;
        s.chars().for_each(|c|{
            *m.entry(c).or_insert(0) += 1;
        });
        t.chars().for_each(|c|{
            match m.get_mut(&c){
                Some(c) => {
                    *c -= 1;
                    if *c < 0 {
                        anagram = false;
                        return
                    }
                },
                None => {
                    anagram = false;
                    return
                }
            }
        });

        anagram
    }
}