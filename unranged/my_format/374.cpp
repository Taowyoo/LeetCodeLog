/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */
// my solution
// binary search
class Solution {
public:
    int guessNumber(int n) {
        int lo = 1;
        int hi = n;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            int res = guess(mid);
            if(res == 0) return mid;
            else if( res > 0) lo = mid + 1;
            else hi = mid - 1;
        }
        return -1;
    }
};