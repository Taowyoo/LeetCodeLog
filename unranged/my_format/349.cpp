// my binary seach solution
// Time: O(nlogn + mlogm)
// Spacke: O(k), let k is size of result vector
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() == 0 || nums2.size() == 0) return {};
        sort(nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
        uniquify(nums2);
        uniquify(nums1);
        vector<int> ans;
        for(int num : nums1){
            if(bs(nums2,num) != -1) ans.emplace_back(num);
        }
        return ans;

    }
    void uniquify(vector<int>& nums){
        int j = 0;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] != nums[j]){
                ++j;
                nums[j] = nums[i];
            }
        }
        nums.resize(j + 1);
    }
    int bs(vector<int>& nums, int target){
        int lo = 0, hi = nums.size() - 1;
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] == target) return mid;
            else if (nums[mid] < target) lo = mid + 1;
            else hi = mid - 1;
        }
        return -1;
    }
};

// hash set soluton
// Time: O(m + n)
// Space: O(m)
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> m(nums1.begin(), nums1.end());
        vector<int> res;
        for (auto a : nums2)
            if (m.count(a)) {
                res.emplace_back(a);
                m.erase(a);
            }
        return res;
    }
};