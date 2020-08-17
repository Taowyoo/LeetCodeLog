// Binary Search + Greedy
// Time: O(n∗log(sum of array))
// Space: O(n)
#define LL long long
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        LL l = 0, r = 0;
        int n = nums.size();
        // set left as min in nums, right as the sum of nums
        for (int i = 0; i < n; i++) {
            r += nums[i];
            if (l < nums[i]) {
                l = nums[i];
            }
        }
        // set initial ans as right
        LL ans =  r;
        // binary search on value of ans between left and right
        while (l <= r) {
            LL mid = (l + r) >> 1;
            // check whether mid is available 
            LL sum = 0;
            int cnt = 1;            
            for (int i = 0; i < n; i++) {
                if (sum + nums[i] > mid) {
                    cnt ++;
                    sum = nums[i];
                } else {
                    sum += nums[i];
                }
            }
            if (cnt <= m) {
                ans = min(ans, mid);
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
//=============================================================================================
// DP
// Time: O(n^2*m)
// Space: O(n*m)
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<int>> f(n + 1, vector<int>(m + 1, INT_MAX));
        vector<long> sub(n + 1, 0);
        for (int i = 0; i < n; i++) {
            sub[i + 1] = sub[i] + nums[i];
        }
        f[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                for (int k = 0; k < i; k++) {
                    f[i][j] = min(f[i][j], max(f[k][j - 1], int(sub[i] - sub[k])));
                }
            }
        }
        return f[n][m];
    }
};