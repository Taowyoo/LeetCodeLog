// dp solution
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // vector<int> dp(nums.size());
        int sum = nums[0];
        int max_sum = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            if(sum < 0){
                sum = nums[i];
            }
            else{
                sum += nums[i];
            }
            max_sum = max(sum,max_sum);
        }
        return max_sum;
    }
}

// divide and conquer
class Solution {
  int crossSum(vector<int>& nums, int left, int right, int p) {
    if (left == right) return nums[left];

    int leftSubsum = INT_MIN;
    int currSum = 0;
    for(int i = p; i > left - 1; --i) {
      currSum += nums[i];
      leftSubsum = std::max(leftSubsum, currSum);
    }

    int rightSubsum = INT_MIN;
    currSum = 0;
    for(int i = p + 1; i < right + 1; ++i) {
      currSum += nums[i];
      rightSubsum = std::max(rightSubsum, currSum);
    }

    return leftSubsum + rightSubsum;
  }

  int helper(vector<int>& nums, int left, int right) {
    if (left == right) return nums[left];

    int p = (left + right) / 2;

    int leftSum = helper(nums, left, p);
    int rightSum = helper(nums, p + 1, right);
    int crossSum = this->crossSum(nums, left, right, p);

    return std::max(std::max(leftSum, rightSum), crossSum);
  }

public:
  int maxSubArray(vector<int>& nums) {
    return helper(nums, 0, nums.size() - 1);
  }
};