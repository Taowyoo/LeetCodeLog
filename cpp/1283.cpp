https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
1283. Find the Smallest Divisor Given a Threshold
class Solution {
    int getSum(vector<int>& nums, int divisor){
        int sum = 0;
        for(int num : nums){
            sum += (num % divisor) ? num / divisor + 1 : num / divisor;
        }
        return sum;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo = 1;
        int hi = 1000001;
        while(lo < hi){
            int mid = (lo + hi) >> 1;
            if(getSum(nums, mid) > threshold){
                lo = mid + 1;
            }
            else{
                hi = mid;
            }
        }
        return lo;
    }
};