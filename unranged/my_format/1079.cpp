// DFS
// 
class Solution {
    int dfs(vector<int>& arr){
        int sum = 0;
        for(int i = 0; i < arr.size(); ++i){
            if(arr[i] == 0) continue;
            --arr[i];
            ++sum;
            sum += dfs(arr);
            ++arr[i];
        }
        return sum;
    }
public:
    int numTilePossibilities(string tiles) {
        vector<int> count(26);
        for(char ch : tiles){
            ++count[ch-'A'];
        }
        return dfs(count);
    }
};