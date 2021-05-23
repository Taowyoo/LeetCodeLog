// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
// 1283. Find the Smallest Divisor Given a Threshold

// my solution
// binary search on possible value field of divisor
// Time: O(nlogm), let n be length of nums, m be the maximun of value field of divisor
// Space: O(1)
class Solution {
    /**
     * @brief get sum of numbers after divided by given divisor
     * 
     * @param nums original input array
     * @param divisor given divisor
     * @return int the sum of array which has been divided by divisor
     */
    int getSum(vector<int>& nums, int divisor){
        int sum = 0;
        for(int num : nums){
            // make check to ensure each result of division is rounded to the nearest integer greater than or equal to that element
            sum += (num % divisor) ? num / divisor + 1 : num / divisor;
        }
        return sum;
    }
public:
    /**
     * @brief find the smallest positive integer divisor that divide all the array by it
     * and sum the result of the division is smaller than given threshold
     * @param nums given array of numbers
     * @param threshold given threshold
     * @return int smallest divisor
     */
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo = 1;
        int hi = 1000001;
        while(lo < hi){
            int mid = (lo + hi) >> 1;
            // check whether this divisor is available
            if(getSum(nums, mid) > threshold){  // if bigger than threshold, let divisor bigger
                lo = mid + 1;
            }
            else{  // if smaller than threshold, let divisor smaller
                hi = mid;
            }
        }
        return lo;
    }
};