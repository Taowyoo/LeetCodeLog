// solution : Merge Intervals
/*
Intuition:

In an interval [a, b], call b the "endpoint".

Among the given intervals, consider the interval A[0] with the smallest endpoint. (Without loss of generality, this interval occurs in array A.)

Then, among the intervals in array B, A[0] can only intersect one such interval in array B. (If two intervals in B intersect A[0], then they both share the endpoint of A[0] -- but intervals in B are disjoint, which is a contradiction.)

Algorithm:

If A[0] has the smallest endpoint, it can only intersect B[0]. After, we can discard A[0] since it cannot intersect anything else.

Similarly, if B[0] has the smallest endpoint, it can only intersect A[0], and we can discard B[0] after since it cannot intersect anything else.

We use two pointers, i and j, to virtually manage "discarding" A[0] or B[0] repeatedly.
*/
// Time: O(n), let n is sum of intervals in A and B
// Space: O(n), let n is size of result vector
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res;
        int i = 0, j = 0;
        while (i < A.size() && j < B.size()) {
            // Let's check if A[i] intersects B[j].
            // lo - the startpoint of the intersection
            // hi - the endpoint of the intersection
            int lo = max(A[i][0], B[j][0]);
            int hi = min(A[i][1], B[j][1]);
            if (lo <= hi)
              res.emplace_back(vector<int>{lo, hi});

            // Remove the interval with the smallest endpoint
            if (A[i][1] < B[j][1]) i++;
            else j++;
        }
        return res;
    }
};
// another  implementation
typedef vector<int> Interval;
vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
  vector<Interval> res;
  for (auto i = 0, j = 0; i < A.size() && j < B.size(); ) {
    if (A[i].end < B[j].start) ++i;
    else if (B[j].end < A[i].start) ++j;
    else {
      res.push_back({ max(A[i].start, B[j].start), min(A[i].end, B[j].end) });
      if (A[i].end < B[j].end) ++i;
      else ++j;
    }
  }
  return res;
}
// another  implementation
vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
    vector<vector<int>> res;
    for (auto i = 0, j = 0; i < A.size() && j < B.size(); A[i][1] < B[j][1] ? ++i : ++j) {
        auto start = max(A[i][0], B[j][0]);
        auto end = min(A[i][1], B[j][1]);
        if (start <= end) 
            res.push_back({start, end});
    }
    return res;    
}