use std::collections::HashMap;

impl Solution {
    pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>> {
        let mut anagrams = HashMap::new();

        for s in strs {
            let mut chars: Vec<char> = s.chars().collect();
            chars.sort_unstable();
            anagrams.entry(chars).or_insert(vec![]).push(s);
        }

        anagrams.into_values().collect()
    }
}
