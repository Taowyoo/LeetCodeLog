// my solution
// use hash table
// Time: O(n)
// Space: O(n)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> count;
        for(int i : nums){
            ++count[i];
        }
        for(auto& key_val : count){
            if(key_val.second == 1) return key_val.first;
        }
        return -1;
    }
};

// use XOR
// Time: O(n)
// Space: O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for(int i : nums){
             x ^= i;
        }
        return x;
    }
};