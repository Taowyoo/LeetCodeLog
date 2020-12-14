/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */
// binary search
// Time: O(logN), let N is max length of array where we find target
// Space: O(1)
class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int lo = 0;
        int hi = 10000;
        const int outrange = 2147483647;
        while(lo < hi){
            int mid = lo + (hi - lo)/2;
            if(reader.get(mid) == outrange) hi = mid;
            else if(reader.get(mid) > target) hi = mid;
            else lo = mid + 1;
        }
        // printf("%d\n",reader.get(lo - 1));
        return reader.get(lo - 1) == target ? lo - 1 : -1;
    }
};