// https://leetcode.com/problems/swim-in-rising-water/
// 778. Swim in Rising Water

// my solution
// using heap and dfs
// find the route by storing point visit state and
// use heap to track the smallest point adjcent to current route to get the next step
// Time: O(nlog(n)), let n is number of all points in the grid
// Space: O(n)
class Solution {
    /**
     * @brief struct for storing point location when putting it in heap
     * 
     */
    struct point{
        int val;
        int x;
        int y;
        point(int val_, int x_, int y_){
            val = val_;
            x = x_;
            y = y_;
        }
    };
    /**
     * @brief points visit state 
     * 
     */
    enum state {
        DEFAULT,
        FOUND,
        VISITED
    };
    int n;  // the length of grid
    int small = INT_MAX;  // smallest point that has meet currently
    int big = INT_MIN;  // biggest point that has meet currently
    vector<point> heap;  // heap for storing all adjcent points to current visited route
    /**
     * @brief check given point, if visited of FOUND before ther return, otherwise
     * record it's value and position to heap
     * @param grid given grid
     * @param status status grid storing points visit status
     * @param i row number to find
     * @param j column number to find
     */
    void find(vector<vector<int>>& grid, vector<vector<int>>& status, int i = 0, int j = 0){
        if(i < 0 || j < 0 || i >=n || j >= n) return;
        if(status[i][j] == VISITED || status[i][j] == FOUND) return;
        heap.push_back(point(grid[i][j],i,j));
        push_heap(heap.begin(),heap.end(),[](point& a, point& b){
            return a.val > b.val;
        });
        status[i][j] = FOUND;
    }
    /**
     * @brief visit given point, and find next point need to visite
     * if has reached adjcent point to the target then return
     * @param grid given grid
     * @param status status grid storing points visit status
     * @param i row number to visit
     * @param j column number to visit
     */
    void visit(vector<vector<int>>& grid, vector<vector<int>>& status, int i = 0, int j = 0){
        status[i][j] = VISITED;
        small = min(small, grid[i][j]);  // update smallest point that we has meet
        big = max(big, grid[i][j]);  // update biggest point that we has meet
        // check whether we have reached adjacent point to target
        if((i == n - 1 && j == n - 2) || (i == n - 2 && j == n - 1)){
            small = min(small, grid[n - 1][n - 1]);
            big = max(big, grid[n - 1][n - 1]);
            return;
        }
        // find(check) adjacent points
        find(grid,status, i - 1 , j);
        find(grid,status, i + 1, j);
        find(grid,status, i , j - 1);
        find(grid,status, i , j + 1);
        // pop smallest point from heap, which is next point to visit
        point p = heap.front();
        pop_heap(heap.begin(),heap.end(),[](point& a, point& b){
            return a.val > b.val;
        });
        heap.pop_back();
        visit(grid,status,p.x,p.y);
    }
public:
    /**
     * @brief  get the least time until you can reach the bottom right square (N-1, N-1)
     * 
     * @param grid given grid
     * @return int min day number
     */
    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        // initialize heap
        vector<vector<int>> status(n, vector<int>(n,DEFAULT));
        heap.clear();
        make_heap(heap.begin(),heap.end(),[](point& a, point& b){
            return a.val > b.val;
        });
        // stimulate route visit
        visit(grid,status);
        // biggest point we have meet is what we need
        return big;
    }
};