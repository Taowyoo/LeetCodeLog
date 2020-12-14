// my dfs solution
// Time: O(M*N)
// Space: O(M*N)
class Solution {
    int num = 0;
    int H;
    int W;
    void dfs(int i, int j, vector<vector<char>>& grid){
        if(i < 0 || j < 0 || i == H || j == W){
            return;
        }else{
            if(grid[i][j] == '1'){
                grid[i][j] = '0';
                dfs(i-1,j,grid);
                dfs(i+1,j,grid);
                dfs(i,j-1,grid);
                dfs(i,j+1,grid);
                return;
            }else{
                return;
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        H = grid.size();
        if(H == 0) return 0;
        W = grid[0].size();
        int res = 0;
        for(int i = 0; i < H; ++i){
            for(int j = 0; j < W; ++j){
                if(grid[i][j] == '1'){
                    ++res;
                    bfs(i,j,grid);
                }
            }
        }
        return res;
    }
};
//======================================================================================
// BFS
// Time: O(M*N)
// Space: O(min(M,N))
class Solution {
public:
  int numIslands(vector<vector<char>>& grid) {
    int nr = grid.size();
    if (!nr) return 0;
    int nc = grid[0].size();

    int num_islands = 0;
    for (int r = 0; r < nr; ++r) {
      for (int c = 0; c < nc; ++c) {
        if (grid[r][c] == '1') {
          ++num_islands;
          grid[r][c] = '0'; // mark as visited
          queue<pair<int, int>> neighbors;
          neighbors.push({r, c});
          while (!neighbors.empty()) {
            auto rc = neighbors.front();
            neighbors.pop();
            int row = rc.first, col = rc.second;
            if (row - 1 >= 0 && grid[row-1][col] == '1') {
              neighbors.push({row-1, col}); grid[row-1][col] = '0';
            }
            if (row + 1 < nr && grid[row+1][col] == '1') {
              neighbors.push({row+1, col}); grid[row+1][col] = '0';
            }
            if (col - 1 >= 0 && grid[row][col-1] == '1') {
              neighbors.push({row, col-1}); grid[row][col-1] = '0';
            }
            if (col + 1 < nc && grid[row][col+1] == '1') {
              neighbors.push({row, col+1}); grid[row][col+1] = '0';
            }
          }
        }
      }
    }

    return num_islands;
  }
};
//======================================================================================
// Union Find (aka Disjoint Set)
// Time: O(M*N)
// Space: O(M*N)
class UnionFind {
public:
  UnionFind(vector<vector<char>>& grid) {
    count = 0;
    int m = grid.size();
    int n = grid[0].size();
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          if (grid[i][j] == '1') {
            parent.emplace_back(i * n + j);
            ++count;
          }
          else parent.emplace_back(-1);
          rank.emplace_back(0);
        }
    }
  }

  int find(int i) { // path compression
    if (parent[i] != i) parent[i] = find(parent[i]);
    return parent[i];
  }

  void Union(int x, int y) { // union with rank
    int rootx = find(x);
    int rooty = find(y);
    if (rootx != rooty) {
      if (rank[rootx] > rank[rooty]) parent[rooty] = rootx;
      else if (rank[rootx] < rank[rooty]) parent[rootx] = rooty;
      else {
        parent[rooty] = rootx; rank[rootx] += 1;
      }
      --count;
    }
  }

  int getCount() const {
    return count;
  }

private:
  vector<int> parent;
  vector<int> rank;
  int count; // # of connected components
};

class Solution {
public:
  int numIslands(vector<vector<char>>& grid) {
    int nr = grid.size();
    if (!nr) return 0;
    int nc = grid[0].size();

    UnionFind uf (grid);
    for (int r = 0; r < nr; ++r) {
      for (int c = 0; c < nc; ++c) {
        if (grid[r][c] == '1') {
          grid[r][c] = '0';
          if (r - 1 >= 0 && grid[r-1][c] == '1') uf.Union(r * nc + c, (r-1) * nc + c);
          if (r + 1 < nr && grid[r+1][c] == '1') uf.Union(r * nc + c, (r+1) * nc + c);
          if (c - 1 >= 0 && grid[r][c-1] == '1') uf.Union(r * nc + c, r * nc + c - 1);
          if (c + 1 < nc && grid[r][c+1] == '1') uf.Union(r * nc + c, r * nc + c + 1);
        }
      }
    }

    return uf.getCount();
  }
};