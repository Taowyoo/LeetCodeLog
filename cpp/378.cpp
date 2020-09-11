// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
// 378. Kth Smallest Element in a Sorted Matrix

// my solution
// merge all rows into one row
// then get Kth smallest element
// Time: O(n^3)
// Space: O(n^2)
class Solution
{
    /**
     * @brief merge given vector into target vector, 
     * use 'beg' to record index of first element of last merged vector to speed up merging
     * 
     * @param dst target vector
     * @param src given vector
     * @param beg index of first element of last merged vector
     * @return int index of first element of just merged vector
     */
    int merge(vector<int> &dst, vector<int> &src, int beg)
    {
        if (dst.empty())
        {
            dst = src;
            return 0;
        }
        int ret = -1;
        int i = beg;
        int j = 0;
        int m = dst.size();
        int n = src.size();
        while (i < m && j < n)
        {
            if (dst[i] < src[j])
            {
                ++i;
            }
            else
            {
                if (ret == -1)
                    ret = i;
                dst.insert(dst.begin() + i, src[j]);
                ++m;
                ++j;
            }
        }
        while (j < n)
        {
            if (ret == -1)
                ret = i;
            dst.emplace_back(src[j++]);
        }
        return ret;
    }

public:
    /**
     * @brief get kth Smallest element in given matrix
     * 
     * @param matrix given matrix with every row or column sorted
     * @param k the number of k for k-th 
     * @return int the value of k-th element
     */
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int n = matrix.size();
        if (n == 0)
            return -1;
        // use a vector to store merged numbers
        vector<int> seq;
        int beg = 0;
        // merge all rows into one row
        for (int i = 0; i < n; ++i)
            beg = merge(seq, matrix[i], beg);
        // return k-th element
        return seq[k - 1];
    }
};

// use heap(priority queue)
// Time: O(N + klogN)
// Space: O(N)
class Solution
{
    /**
 * @brief struct for store one element in the given array with
 * its value, row number, column number
 * 
 */
    struct element
    {
        int value;
        int row;
        int column;
    };

    struct compare
    {
        /**
     * @brief comparer for comparing customized 'element' by it's value field
     * 
     * @param a one data
     * @param b another data
     * @return true a is bigger then b 
     * @return false a is not bigger than b
     */
        bool operator()(const element &a, const element &b)
        {
            return a.value > b.value;
        }
    };

public:
    int kthSmallest(vector<vector<int>> &arr, int k)
    {

        int n = arr.size(), m = arr[0].size();
        // use a three varaiable struct to store the element of each row and its row number and column number
        priority_queue<element, vector<element>, compare> p;

        // put first element of each row into the priority_queue
        for (int i = 0; i < n; i++)
            p.push(element{arr[i][0], i, 0});

        // loop k times to find k-th smallest number
        int x = k, ans;
        while (x--)
        {
            // get data of current smallest element
            // which is (k - x)th smallest element
            int e = p.top().value;
            int i = p.top().row;
            int j = p.top().column;
            ans = e;        // update answer
            p.pop();        // pop current smallest
            if (j != m - 1) // do not push new element if reach end of row
                p.push(element{arr[i][j + 1], i, j + 1});
        }
        return ans;
    }
};

// binary search
class Solution
{
public:
    static int findKthSmallest(vector<vector<int>> &matrix, int k)
    {
        int n = matrix.size();
        int start = matrix[0][0], end = matrix[n - 1][n - 1];
        while (start < end)
        {
            int mid = start + (end - start) / 2;
            // first number is the smallest and the second number is the largest
            pair<int, int> smallLargePair = {matrix[0][0], matrix[n - 1][n - 1]};
            int count = countLessEqual(matrix, mid, smallLargePair);
            if (count == k)
            {
                return smallLargePair.first;
            }

            if (count < k)
            {
                start = smallLargePair.second; // search higher
            }
            else
            {
                end = smallLargePair.first; // search lower
            }
        }

        return start;
    }

private:
    static int countLessEqual(vector<vector<int>> &matrix, int mid, pair<int, int> &smallLargePair)
    {
        int count = 0;
        int n = matrix.size(), row = n - 1, col = 0;
        while (row >= 0 && col < n)
        {
            if (matrix[row][col] > mid)
            {
                // as matrix[row][col] is bigger than the mid, let's keep track of the
                // smallest number greater than the mid
                smallLargePair.second = min(smallLargePair.second, matrix[row][col]);
                row--;
            }
            else
            {
                // as matrix[row][col] is less than or equal to the mid, let's keep track of the
                // biggest number less than or equal to the mid
                smallLargePair.first = max(smallLargePair.first, matrix[row][col]);
                count += row + 1;
                col++;
            }
        }
        return count;
    }
};

// 