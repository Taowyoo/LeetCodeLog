// my solution
// one pass
// Time: O(n)
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        if(arr.size() < 3) return false;
        int count = 0;
        for(int i = 1; i < arr.size(); ++i){
            if(isOdd(arr[i]) && isOdd(arr[i - 1])){
                if(count == 0) count = 2;
                else return true;
            }
            else{
                count = 0;
            }
        }
        return false;
    }
private:
    bool isOdd(int num){
        return num % 2 == 1;
    }
};
//================================================================
// shorter & better
bool threeConsecutiveOdds(vector<int>& arr) {
    int odds = 0;
    for (auto i = 0; i < arr.size() && odds < 3; ++i)
        odds = arr[i] % 2 ? odds + 1 : 0;
    return odds == 3;
}