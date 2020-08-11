// my solution
// time: O(n)
// memory: O(n)
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int c = K;
        for(auto it = A.rbegin(); it != A.rend(); ++it){
            if(c == 0) break;
            c += *it;
            *it = c % 10;
            c /= 10;
        }
        vector<int> extra = {};
        while(c != 0){
            extra.emplace_back(c % 10);
            c /= 10;
        }
        reverse(extra.begin(),extra.end());
        A.insert(A.begin(),extra.begin(),extra.end());
        return A;
    }
};

// better apporach for this problem
// EXPLANATION
// Take K as a carry.
// Add it to the lowest digit,
// Update carry K,
// and keep going to higher digit.

// COMPLEXITY
// Insert will take O(1) time or O(N) time on shifting, depending on the data stucture.
// But in this problem K is at most 5 digit so this is restricted.
// So this part doesn't matter.
// The overall time complexity is O(N).
// For space I'll say O(1)
vector<int> addToArrayForm(vector<int> A, int K) {
    for (int i = A.size() - 1; i >= 0 && K > 0; --i) {
        A[i] += K;
        K = A[i] / 10;
        A[i] %= 10;
    }
    while (K > 0) {
        A.insert(A.begin(), K % 10);
        K /= 10;
    }
    return A;
}