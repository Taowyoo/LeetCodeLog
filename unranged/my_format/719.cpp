// Binary Search + Sliding Window
// Time: O(NlogW+NlogN)
// Space: O(1)
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        // sort nums
        sort(nums.begin(),nums.end());
        int lo = 0;
        int hi = nums[nums.size() - 1] - nums[0];
        while (lo < hi) {
            int mi = (lo + hi) / 2;
            int count = 0, left = 0;
            for (int right = 0; right < nums.size(); ++right) {
                while (nums[right] - nums[left] > mi) left++;
                count += right - left;
            }
            //count = number of pairs with distance <= mi
            if (count >= k) hi = mi;
            else lo = mi + 1;
        }
        return lo;
    }
};
//=================================================================================================================
// Binary Search + Prefix Sum
// Time: O(W+NlogW+NlogN), where NN is the length of nums, and WW is equal to nums[nums.length - 1] - nums[0].
//  We do O(W) work to calculate prefix initially. 
//  The logW factor comes from our binary search, and we do O(N) work inside our call to possible (or to calculate count in Java).
//  The final O(NlogN) factor comes from sorting.
// Space: O(N+W), the space used to store multiplicity and prefix.
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        // sort nums
        sort(nums.begin(),nums.end());
        int WIDTH = 2 * nums[nums.size() - 1];

        //multiplicity[i] = number of nums[j] == nums[i] (j < i)
        vector<int> multiplicity(nums.size());
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i-1]) {
                multiplicity[i] = 1 + multiplicity[i - 1];
            }
        }

        //prefix[v] = number of values <= v
        vector<int> prefix(WIDTH);
        int left = 0;
        for (int i = 0; i < WIDTH; ++i) {
            while (left < nums.size() && nums[left] == i) left++;
            prefix[i] = left;
        }

        int lo = 0;
        int hi = nums[nums.size() - 1] - nums[0];
        while (lo < hi) {
            int mi = (lo + hi) / 2;
            int count = 0;
            for (int i = 0; i < nums.size(); ++i) {
                count += prefix[nums[i] + mi] - prefix[nums[i]] + multiplicity[i];
            }
            //count = number of pairs with distance <= mi
            if (count >= k) hi = mi;
            else lo = mi + 1;
        }
        return lo;
    }
};

