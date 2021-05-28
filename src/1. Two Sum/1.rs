use std::collections::HashMap;
impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut index_hashmap = HashMap::new();

        for (idx, &n) in nums.iter().enumerate() {
            if let Some(&i) = index_hashmap.get(&(target - n)) {
                return vec![i as i32, idx as i32];
            } else {
                index_hashmap.insert(n, idx);
            }
        }

        vec![]
    }
}