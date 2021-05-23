// use hash table 
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> count;
        for(int i : nums){
            ++count[i];
        }
        vector<int> res;
        for(auto& key_val : count){
            if(key_val.second == 1) res.emplace_back(key_val.first);
        }
        return res;
    }
};

// Bit manipulatation
// Explaination:
// Once again, we need to use XOR to solve this problem. But this time, we need to do it in two passes:
// In the first pass, we XOR all elements in the array, and get the XOR of the two numbers we need to find. 
//   Note that since the two numbers are distinct, so there must be a set bit (that is, the bit with value '1') in the XOR result. 
//   Findout an arbitrary set bit (for example, the rightmost set bit).
// In the second pass, we divide all numbers into two groups, one with the aforementioned bit set, another with the aforementinoed bit unset.
//   Two different numbers we need to find must fall into thte two distrinct groups. 
//   XOR numbers in each group, we can find a number in either group.
// Complexity:
// Time: O (n)
// Space: O (1)
// A Corner Case:
// When diff == numeric_limits<int>::min(), -diff is also numeric_limits<int>::min(). Therefore, the value of diff after executing diff &= -diff is still numeric_limits<int>::min(). The answer is still correct.
class Solution
{
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        // Pass 1 : 
        // Get the XOR of the two numbers we need to find
        int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        // Get its last set bit
        diff &= -diff;

        // Pass 2 :
        vector<int> rets = {0, 0}; // this vector stores the two numbers we will return
        for (int num : nums)
        {
            if ((num & diff) == 0) // the bit is not set
            {
                rets[0] ^= num;
            }
            else // the bit is set
            {
                rets[1] ^= num;
            }
        }
        return rets;
    }
};