/*
 * File: 1673.cpp
 * Created Date: 2021-01-21
 * Author: Nick Cao(caoyxsh@outlook.com)
 * Brief: https://leetcode.com/problems/find-the-most-competitive-subsequence/
 * -----
 * Last Modified: 2021-01-21T14:26:48-08:00
 * Modified By: Nick Cao(caoyxsh@outlook.com)
 */


// Intuition
// Use a mono incrasing stack.


// Explanation
// Keep a mono incrasing stack as result.
// If current element a is smaller then the last element in the stack,
// we can replace it to get a smaller sequence.

// Before we do this,
// we need to check if we still have enough elements after.
// After we pop the last element from stack,
// we have stack.size() - 1 in the stack,
// there are A.size() - i can still be pushed.
// if stack.size() - 1 + A.size() - i >= k, we can pop the stack.

// Then, is the stack not full with k element,
// we push A[i] into the stack.

// Finally we return stack as the result directly.


// Complexity
// Time O(n)
// Space O(k)

// by @lee215
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& A, int k) {
        vector<int> stack;
        for (int i = 0; i < A.size(); ++i) {
            while (!stack.empty() && stack.back() > A[i] && stack.size() - 1 + A.size() - i >= k)
                stack.pop_back();
            if (stack.size() < k)
                stack.push_back(A[i]);
        }
        return stack;
    }
};

// Summary:
// A key idea have to remember is:
// All subsequence of a array can be generate by push and pop into another stack