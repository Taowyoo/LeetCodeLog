use std::collections::{HashSet, VecDeque};

impl SolutionBFS {
    pub fn num_islands(grid: Vec<Vec<char>>) -> i32 {
        let mut answer = 0;
        let mut hs: HashSet<(usize, usize)> = HashSet::new();
        for i in 0..grid.len() {
            for j in 0..grid[i].len() {
                if grid[i][j] == '1' && !hs.contains(&(i, j)) {
                    answer += 1;
                    let mut d: VecDeque<(usize, usize)> = VecDeque::new();
                    d.push_back((i, j));
                    while let Some(f) = d.pop_front() {
                        if hs.contains(&(f.0, f.1)) {
                            continue;
                        }
                        hs.insert((f.0, f.1));
                        if f.0 > 0 && grid[f.0 - 1][f.1] == '1' {
                            d.push_back((f.0 - 1, f.1))
                        }
                        if f.1 > 0 && grid[f.0][f.1 - 1] == '1' {
                            d.push_back((f.0, f.1 - 1))
                        }
                        if f.0 < grid.len() - 1 && grid[f.0 + 1][f.1] == '1' {
                            d.push_back((f.0 + 1, f.1))
                        }
                        if f.1 < grid[0].len() - 1 && grid[f.0][f.1 + 1] == '1' {
                            d.push_back((f.0, f.1 + 1))
                        }
                    }
                }
            }
        }
        answer        
    }
}

impl SolutionDFS {
    pub fn num_islands(mut grid: Vec<Vec<char>>) -> i32 {
        
        fn dfs(grid: &mut Vec<Vec<char>>, x: usize, y: usize) {
            if grid[x][y] == '0' {
                return;
            }
            
            grid[x][y] = '0';
            
            if x > 0 { 
                dfs(grid, x - 1, y); 
            }
            if y > 0 { 
                dfs(grid, x, y - 1); 
            }
            if x < grid.len() - 1 { 
                dfs(grid, x + 1, y); 
            }
            if y < grid[0].len() - 1 { 
                dfs(grid, x, y + 1); 
            }
        }
        
        let mut result = 0;
        
        for x in (0..grid.len()){
            for y in (0..grid[0].len()){
                if grid[x][y] == '1' {
                    dfs(&mut grid, x, y);
                    result += 1;
                }
            }
        }
        
        result
    }
}


// union find solution

struct UnionFind {
    parents: Vec<i32>,
    count: i32,
    rank: Vec<i32>,
}

impl UnionFind {

    
    fn new(grid: &Vec<Vec<char>>) -> Self {
        let m = grid.len();
        let n = grid[0].len();
        let mut count = 0;
        let mut parents = vec![-1; m * n];
        let rank = vec![0; m * n];
		
        for i in 0..m {
            for j in 0..n {
                if grid[i][j] == '1' {
                    parents[i * n + j] = (i * n + j) as i32;
                    count += 1;
                }
            }
        }
        UnionFind { parents: parents, count: count, rank: rank }
    }

    fn find(&mut self, i: i32) -> i32 {
        if self.parents[i as usize] != i { 
            self.parents[i as usize] = self.find(self.parents[i as usize]) 
        };
        self.parents[i as usize]
    }

    fn union(&mut self, x: i32, y: i32) -> i32 {
        let x_parent = self.find(x);
        let y_parent = self.find(y);

        if x_parent == y_parent { return self.count; }

        if self.rank[x_parent as usize] < self.rank[y_parent as usize] {
            self.parents[x_parent as usize] = y_parent;
        } else if self.rank[x_parent as usize] > self.rank[y_parent as usize] {
            self.parents[y_parent as usize] = x_parent;
        } else {
            self.parents[y_parent as usize] = x_parent;
            self.rank[y_parent as usize] += 1;
        }
        self.count -= 1;

        self.count
    }
}

impl Solution {
    pub fn num_islands(grid: Vec<Vec<char>>) -> i32 {
        if grid.is_empty() { return 0; }
        
        let directions: Vec<(i32, i32)> = vec![(-1, 0), (1, 0), (0, -1), (0, 1)];
        let (m, n) = (grid.len(), grid[0].len());
        let mut uf = UnionFind::new(&grid);

        for i in 0..m {
            for j in 0..n {
                if grid[i][j] == '0' { continue; }

                for d in &directions {
                    let (dr, dc) = (i as i32 + d.0, j as i32 + d.1);
                    if dr >= 0 && 
                       dc >= 0 && 
                       dr < m as i32 && 
                       dc < n as i32 && 
                       grid[dr as usize][dc as usize] == '1' {
                        uf.union((i * n + j) as i32, dr * n as i32 + dc);
                    }
                }
            }
        }
        uf.count

    }
}