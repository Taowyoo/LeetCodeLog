// always take the second most pile of coins
// Time: O(sort)
// Space: O(sort)
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int times = piles.size() / 3;
        // vector<int> my;
        int my = 0;
        int i = piles.size() - 2;
        for(int j = 0; j < times ; ++j){
            my+= piles[i];
            i -= 2;
        }
        return my;
    }
};