// sort solution
// Time: O(nlogn + mlogm)
// Space: O(logm + log n) ~ O(m + n) depends on implementation of sort
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(begin(nums1), end(nums1));
        sort(begin(nums2), end(nums2));
        int i = 0, j = 0, k = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                ++i;
            } else if (nums1[i] > nums2[j]) {
                ++j;
            } else {
                nums1[k++] = nums1[i++];
                ++j;
            }
        }
        return vector<int>(begin(nums1), begin(nums1) + k);
    }
};
//=============================================================================
// hash solution
// Time: O(n+m)
// Space: O(min(n,m))
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) {
        return intersect(nums2, nums1);
    }
    unordered_map<int, int> m;
    for (auto n : nums1) {
        ++m[n];
    }
    int k = 0;
    for (auto n : nums2) {
        auto it = m.find(n);
        if (it != end(m) && --it->second >= 0) {
            nums1[k++] = n;
        }
    }
    return vector(begin(nums1), begin(nums1) + k);
}