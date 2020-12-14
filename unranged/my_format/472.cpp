// https://leetcode.com/problems/heaters/
// 475. Heaters

// my solution
// binary search on available radius
// to speed up check function, sort the houses and heaters
// Time: O(log(MaxRange)*Max(houses, heaters)), let houses, heaters be the length of each array and MaxRange is max possible length of radius
// Space: O(sort)
class Solution {
    /**
     * @brief check whether specific radius is available
     * 
     * @param houses houses position array
     * @param heaters heaters position array
     * @param radius given radius
     * @return true current radius is available
     * @return false current radius is unavailable
     */
    bool check(vector<int>& houses, vector<int>& heaters, int radius){
        int i = 0;
        for(int j = 0; j < heaters.size(); ++j){
            while(i < houses.size() && houses[i] <= heaters[j] + radius){
                if(houses[i] < heaters[j] - radius) return false;
                else{
                    ++i;
                }
            }
        }
        if(i != houses.size()) return false;
        return true;
    }
public:
    /**
     * @brief find minimal radius for heaters that enable heaters can heat all houses
     * 
     * @param houses position array of houses
     * @param heaters position array of heaters
     * @return int minimal radius value
     */
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int hi = 1e9;
        int lo = 0;
        // sort to speed up check process
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        // binary search on radius
        while(lo < hi){
            int mid = (hi + lo) >> 1;
            if(check(houses, heaters, mid))
                hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};

// others' approach 1
// Time: O(sort)
// Space: O(houses.size())
class Solution {
public:
    /**
     * @brief find minimal radius for heaters that enable heaters can heat all houses
     * Description: by computer each houses' minimal distance to its left or right heater
     *              we can find the minimal heater radius by get max value in these minimal distance
     * Example:    h = house,  * = heater  M = INT_MAX
     * 
     *      h   h   h   h   h   h   h   h   h    houses
     *      1   2   3   4   5   6   7   8   9    index
     *      *           *       *                heaters
     *               
     *      0   2   1   0   1   0   -   -   -    (distance to nearest RHS heater)
     *      0   1   2   0   1   0   1   2   3    (distance to nearest LHS heater)
     *
     *      0   1   1   0   1   0   1   2   3    (res = minimum of above two)
     *
     * Result is maximum value in res, which is 3. 
     * 
     * @param houses position array of houses
     * @param heaters position array of heaters
     * @return int minimal radius value
     */
    int findRadius(vector<int>& A, vector<int>& H) {
        sort(A.begin(), A.end());
        sort(H.begin(), H.end());
        vector<int> res(A.size(), INT_MAX); 
        
        // For each house, calculate distance to nearest RHS heater
        for (int i = 0, h = 0; i < A.size() && h < H.size(); ) {
            if (A[i] <= H[h]) { res[i] = H[h] - A[i]; i++; }
            else { h++; }
        }
        
        // For each house, calculate distance to nearest LHS heater
        for (int i = A.size()-1, h = H.size()-1; i >= 0 && h >= 0; ) {
            if (A[i] >= H[h]) { res[i] = min(res[i], A[i] - H[h]); i--; }
            else { h--; }
        }
       
        return *max_element(res.begin(), res.end());
    }
};

// others' approach 2
class Solution {
public:
    /**
     * @brief find minimal radius for heaters that enable heaters can heat all houses
     * same to approach 1, but use binary search to find the nearest heaters near one house
     * @param houses position array of houses
     * @param heaters position array of heaters
     * @return int minimal radius value
     */
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int result = INT_MIN;
        
        for (int house : houses) {
            auto ite = lower_bound(heaters.begin(),heaters.end(), house);
            int index = ite - heaters.begin();
            int dist1 = index - 1 >= 0 ? house - heaters[index - 1] : INT_MAX;
            int dist2 = index < heaters.size() ? heaters[index] - house : INT_MAX;
        
            result = std::max(result, std::min(dist1, dist2));
        }
        
        return result;
    }
};