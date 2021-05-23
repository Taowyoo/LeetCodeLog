// https://leetcode.com/problems/h-index-ii/
// 275. H-Index II

// binary search
class Solution {
public:
    /**
     * @brief get the h-index of a person by checking his or her paper citations
     * use binary search, searching on range of the answer(h-index)
     * @param citations paper citations number array
     * @return int h-index number
     */
    int hIndex(vector<int>& citations) {
        if(citations.empty()) return 0;
        int N = citations.size();
        // possible h-index should be [0,N), N is length of citations vector
        int lo = 0;
        int hi = N - 1;
        // we knew that there is  N - i number articles that are cited at least citations[i] times
        // because the citations vector is sorted in ascending order
        // so when certain citations[i] >= N - i , the N - i is the h-index we need
        // by using binary search, we are going to find the first(leftmost) citations[i] that meet the requirement
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            if(citations[mid] >= N - mid ){ // find whether there is a smaller i(bigger h-index)
                hi = mid - 1;
            }
            else{  // the available h-index is on the right
                lo = mid + 1;
            }
        }
        return N - lo;
    }
};