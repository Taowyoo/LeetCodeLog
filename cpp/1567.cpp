// my solution
// split array by 0, any use two pointer to check max length of each sub array
// Time: O(n)
// Space: O(1)
class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        if(nums.size() < 1) return 0;
        int res = 0;
        int left = 0;
        while(left < nums.size()){
            for(int i = left; i <= nums.size(); ++i){
                if(i == nums.size() || nums[i] == 0){
                    int hi = i;
                    int lo = left;
                    // check [lo, hi)
                    int tmp = 1;
                    for(int j = lo; j < hi; ++j){
                        if(tmp > 0 && nums[j] > 0 || tmp < 0 && nums[j] < 0){
                            tmp = 1;
                        }
                        else{
                            tmp = -1;
                        }
                    }
                    if(tmp > 0){
                        res = max(res, hi - lo);
                    }
                    else{
                        int tmp = lo;
                        while(tmp < hi && nums[tmp] > 0) ++tmp;
                        res = max(res, hi - tmp - 1);
                        tmp = hi;
                        while(lo < tmp && nums[tmp - 1] > 0) --tmp;
                        res = max(res, tmp - lo - 1);
                    }
                    left = i + 1;
                    break;
                }
            }
        }
        return res;
    }
};

// clearer and simpler approach
class Solution {
public:
    int getMaxLen(vector<int>& nums)
    {
        int firstNegative = -1, zeroPosition = -1, sum = 0, max = 0;
        for(int i = 0;i < nums.size(); i++){
            if(nums[i] < 0){
                sum++;
				// we only need to know index of first negative number
                if(firstNegative == -1) firstNegative = i;
            }
			// if current number is 0, we can't use any element from index 0 to i anymore, so update zeroPosition, and reset sum and firstNegative. If it is a game, we should refresh the game when we meet 0. 
            if(nums[i] == 0){
                sum = 0;
                firstNegative = -1;
                zeroPosition = i;
            }
            else{
			    // consider index of zero
                if(sum%2 == 0) max = std::max(i - zeroPosition, max);
				// consider index of first negative number
                else max = std::max(i - firstNegative, max);   
            }
        }
        return max;
    }
};