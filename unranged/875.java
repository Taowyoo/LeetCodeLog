// https://leetcode.com/problems/koko-eating-bananas/
// 875. Koko Eating Bananas

class Solution {
    int getEatHours(int num, int speed){
        return (num + speed - 1) / speed;
    }
    bool canEatAll(std::vector<int> piles, int speed, int H){
        int hours = 0;
        for(int pile : piles){
            hours += getEatHours(pile, speed);
        }
        return hours <= H;
    }
    int solve(std::vector<int> piles, int H){
        int low = 1;
        int high = 1;
        for(int pile : piles){
            high = max(high, pile);
        }
        while(low < high){
            int mid = low + (high - low) / 2;
            if(canEatAll(piles,mid,H))
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        return solve(piles, H);
    }
};