// my solution
// fill the vector num1 from end to begin, fill bigger number first
// Time: O(n)
// Space: O(1)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m + n - 1;
        --m;
        --n;
        while(m >= 0 && n >= 0){
            int val1 = nums1[m];
            int val2 = nums2[n];
            if(val1 > val2){
                nums1[i--] = val1;
                --m;
            }
            else{
                nums1[i--] = val2;
                --n;
            }
        }
        if(m >= 0){
            while(m >= 0) nums1[i--] = nums1[m--];
        }
        else{
            while(n >= 0) nums1[i--] = nums2[n--];
        }
        
    }
};

