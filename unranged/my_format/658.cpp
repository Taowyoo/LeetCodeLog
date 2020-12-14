// my solution
// 1. find nearest pos to x 
// 2. find K Closest element near the position just found
// Time: O(log2(n)+k)
// Space: O(k)
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // corner cases
        if(arr.empty()) return vector<int>{};
        if(x < arr.front()) return vector<int>(arr.begin(),arr.begin() + k);
        if(x > arr.back()) return vector<int>(arr.end() - k, arr.end());
        // find x
        int lo = 0, hi = arr.size();
        while(lo < hi){
            int mid = lo + (hi - lo) / 2;
            if(arr[mid] > x) hi = mid;
            else lo = mid + 1;
        }
        int index = lo - 1;
        // printf("index = %d\n",index);
        if(arr[index] != x && index + 1 < arr.size()){
            index = arr[index + 1] - x < x - arr[index] ? index + 1 : index;
        }
        if(k == 1) return vector<int>{arr[index]};
        // printf("index = %d\n",index);
        int le = index , ri = index ;
        while(--k){
            int left = le - 1 >= 0 ? arr[le - 1] : INT_MAX;
            int right = ri + 1 < arr.size() ? arr[ri + 1] : INT_MAX;
            if(left == INT_MAX){
                ri++;
                continue;
            }
            if(right == INT_MAX){
                le--;
                continue;
            }
            if(x - left < right - x){
                le--;
            }
            else if(x - left == right - x){
                if(left <= right) le--;
                else ri++;
            }
            else{
                ri++;
            }
        }
        le = std::max(le,0);
        ri = std::min(ri,(int)arr.size());
        return vector<int>(arr.begin()+le,arr.begin()+ri+1);
    }
};
// shorter version
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int index = std::lower_bound(arr.begin(), arr.end(), x) - arr.begin();
    int i = index - 1, j = index;                                    
    while(k--) (i<0 || (j<arr.size() && abs(arr[i] - x) > abs(arr[j] - x) ))? j++: i--;
    return vector<int>(arr.begin() + i + 1, arr.begin() + j );
}
//=================================================================================================
// once binary search solution
// Time: O(O(log(N-K) + K))
vector<int> findClosestElements(vector<int>& A, int k, int x) {
    int left = 0, right = A.size() - k;
    while (left < right) {
        int mid = (left + right) / 2;
        if (x - A[mid] > A[mid + k] - x)
            left = mid + 1;
        else
            right = mid;
    }
    return vector<int>(A.begin() + left, A.begin() + left + k);
}
//=================================================================================================
// use sort
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        sort(begin(arr), end(arr), [&x] (const auto &a, const auto &b) {
            if(abs(a - x) == abs(b - x))
                return a < b;
            return abs(a - x) < abs(b - x);
        });
        arr.erase(begin(arr) + k, end(arr));
        // arr.resize(k);
        sort(begin(arr), end(arr));
        return arr;
    }
};

