// my solution
// count every sector times
// Time: O(N) let N is the total length of marathon 
// Space: O(N)
class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<vector<int>> count(n, vector<int>(2));
        for(int i  = 0; i < count.size(); ++i){
            count[i][0] = i + 1;
        }
        ++count[rounds[0] - 1][1];
        for(int i = 0; i + 1 < rounds.size(); ++i){
            if(rounds[i] < rounds[i + 1]){
                for(int j = rounds[i] + 1; j <= rounds[i + 1]; ++j){
                    ++count[j - 1][1];
                }
            }
            else{
                for(int j = rounds[i] + 1; j <= n; ++j){
                    ++count[j - 1][1];
                }
                for(int j = 1; j <= rounds[i + 1]; ++j){
                    ++count[j - 1][1];
                }
            }
        }
        int most = 0;
        for(auto val : count){
            most = max(most, val[1]);
        }
        vector<int> ans;
        for(auto val : count){
            if(most == val[1]) ans.emplace_back(val[0]);
        }
        return ans;
    }
};
//========================================================================
// From start to end
// only need to care start and end
// Time: O(N), let N is length of vector
// Space: O(1)
class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& A) {
        vector<int> res;
        for (int i = A[0]; i <= A[A.size() - 1]; ++i)
            res.push_back(i);
        if (res.size() > 0) return res;
        for (int i = 1; i <= A[A.size() - 1]; ++i)
            res.push_back(i);
        for (int i = A[0]; i <= n; ++i)
            res.push_back(i);
        return res;
    }
}
