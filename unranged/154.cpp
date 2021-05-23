// my solution
// mainly use binary search
// for mid == high case use recursive search
// Time:O(n)
// Spacke: O(n)
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.back() > nums.front()) return nums.front();
        return findMin(nums, 0, nums.size() - 1);
    }
private:
    int findMin(vector<int>& nums, int lo, int hi){
        if(lo > hi) return INT_MAX;
        while(lo < hi){
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] == nums[hi]) return min(findMin(nums,lo,mid),findMin(nums,mid+1,hi));
            else if(nums[mid] > nums[hi]) lo = mid + 1;
            else hi = mid;
        }
    }
};
//===========================================================================
// best binary search
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.back() > nums.front()) return nums.front();
        int lo = 0, hi = nums.size() - 1;
        while(lo < hi){
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] == nums[hi]) --hi;
            else if(nums[mid] > nums[hi]) lo = mid + 1;
            else hi = mid;
        }
        return nums[lo];
    }

};