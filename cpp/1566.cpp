// my solution
// Time: O((n-m*k)*m*k)
// Space: O(1)
class Solution {
    bool check(vector<int>& arr, int beg,int m, int k){
        for(int j = beg; j < beg + m; ++j){
            for(int i = 1; i < k; ++i){
                if(arr[j + i*m] != arr[j + (i-1)*m]) return false;
            }
        }
        return true;
    }
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int total = m * k;
        if(total > arr.size()) return false;
        for(int i = 0; i < arr.size() - total + 1; ++i){
            if(check(arr, i, m , k)) return true;
        }
        return false;
    }
};
// better approach
class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int cnt=0;
        for(int i=0;i+m < arr.size(); i++){
            
            if(arr[i]!=arr[i+m]){
              cnt=0;  
            }
            cnt += (arr[i] == arr[i+m]);
            if(cnt == (k-1)*m)
                return true;
            
        }
        return false;
    }
};