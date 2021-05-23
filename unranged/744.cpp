// my original binary search solution
// Time: O(logn)
// SpaceL O(1)
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        // binary search by letter
        int lo = 0;
        int hi = letters.size();
        // find the pos of first letter that >= target + 1, which is equal to answer
        target = target == 'z' ? 'a' : target + 1;  
        while(lo < hi){
            int mid = lo + (hi - lo) / 2;
            if(letters[mid] < target) lo = mid + 1;
            else hi = mid;
        }
        // coner case
        if(lo >= letters.size()) return letters[0];
        
        return letters[lo];
    }
};
//==================================================================================================
// better version
//  find the rightmost position to insert target into letters so that it remains sorted
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int lo = 0, hi = letters.size();
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            if (letters[mi] <= target) lo = mi + 1;
            else hi = mi;
        }
        return letters[lo % letters.size()];
    }
};