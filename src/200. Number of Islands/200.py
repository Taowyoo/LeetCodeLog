'''
File: 200.py
Created Date: 2021-03-08
Author: Nick Cao(caoyxsh@outlook.com)
Brief: https://leetcode.com/problems/number-of-islands/
-----
Last Modified: 2021-03-08T10:08:44-08:00
Modified By: Nick Cao(caoyxsh@outlook.com)
'''


class Solution1:
    def numIslands(self, grid: List[List[str]]) -> int:
		"""DFS Solution
        Args:
                grid (List[List[str]]): Island grid
        Returns:
                int: Island number
        """
		dx = [1, -1, 0, 0]
        dy = [0, 0, 1, -1]
        if not grid:
            return 0
        rows = len(grid)
        if rows == 0:
            return 0
        cols = len(grid[0])
        if cols == 0:
            return 0

        def dfs(i: int, j: int) -> int:
            if i < 0 or i >= rows or j < 0 or j >= cols:
                return 0
            if grid[i][j] == "1":
                grid[i][j] = "0"
                for x, y in zip(dx, dy):
                    dfs(i+x, j+y)
                return 1
            else:
                return 0
        res = 0
        for x in range(rows):
            for y in range(cols):
                res += dfs(x, y)
        return res
