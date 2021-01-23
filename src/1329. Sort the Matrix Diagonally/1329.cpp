/*
 * File: 1329.cpp
 * Created Date: 2021-01-23
 * Author: Nick Cao(caoyxsh@outlook.com)
 * Brief: https://leetcode.com/problems/sort-the-matrix-diagonally/
 * -----
 * Last Modified: 2021-01-23T08:16:48-08:00
 * Modified By: Nick Cao(caoyxsh@outlook.com)
 */

/**
 * @brief Approach 1: HashMap of Heaps
 * Time: O(N×M×log(min(N,M)))
 * Space: O(N×M)
 * where NN is a number of rows and MM is a number of columns
 */
class Solution {
    typedef priority_queue<int, std::vector<int>, std::greater<int> > pq;
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        // hashmap to keep the diagonals
        unordered_map<int, pq> h ;
        
        // fill the hashmap
        int n = mat.size(), m = mat[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) { 
                if(!h.count(i-j)) h[i-j] = pq{};
                h[i-j].push(mat[i][j]);
            }   
        }

        // build output
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                mat[i][j] = h[i - j].top();
                h[i - j].pop();
            }
        }
        
        return mat;
    }
};

/**
 * @brief Approach 2: Sort Diagonals One by One Using Sort
 * Time: O(N×M×log(min(N,M)))
 * Space: O(min(N,M))
 * where NN is a number of rows and MM is a number of columns
 */
class Solution {
    vector<vector<int>> mat;
    int n, m;
    void sortDiagonal(int i, int j) {
        vector<int> diagonal;
        // store the current diagonal 
        // in the list
        while (i < n && j < m) {
            diagonal.push_back(mat[i][j]);
            ++i;
            ++j;    
        }

        // sort the diagonal values
        sort(diagonal.begin(),diagonal.end());

        // push the sorted values 
        // back into the matrix
        while (i > 0 && j > 0) {
            --i;
            --j;
            mat[i][j] = diagonal.back();
            diagonal.pop_back();
        }
    }
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        this->mat = mat;
        n = mat.size();
        m = mat[0].size();
                
        // sort all diagonals 
        // in the lower left corner
        for (int i = 0; i < n; ++i) {
            sortDiagonal(i, 0);       
        } 
        // sort all diagonals 
        // in the upper right corner
        for (int j = 0; j < m; ++j) {
            sortDiagonal(0, j);  
        } 
        return this->mat;
    }
};