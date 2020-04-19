# Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. 
# An island is surrounded by water and is formed by connecting adjacent lands 
# horizontally or vertically. 
# 
# You may assume all four edges of the grid are all surrounded by water.

#  Input:
# 0 0 0 0 0 0 
# 0 1 1 1 1 0
# 0 1 1 0 1 0
# 0 1 1 0 0 0
# 0 0 0 0 0 0

# Output: 1

# Input:
# 1 1 0 0 0
# 1 1 0 0 0
# 0 0 1 0 0
# 0 0 0 1 1

# // Output: 3
from typing import List

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if grid is None or len(grid) == 0:
            return 0

        count = 0
        WIDTH = len(grid)
        HEIGHT = len(grid[0])

        for x in range(WIDTH):
            for y in range(HEIGHT):
                if grid[x][y] == '1':
                    count += 1
                    self.flood_fill(grid, x, y, WIDTH, HEIGHT)

        return count

    def flood_fill(self, grid: List[List[str]], x: int, y: int, WIDTH, HEIGHT):
        if (x < 0 or x >= WIDTH) or (y < 0 or y >= HEIGHT):
            return

        if grid[x][y] == '0':
            return

        grid[x][y] = '0'

        self.flood_fill(grid, x-1, y, WIDTH, HEIGHT)
        self.flood_fill(grid, x+1, y, WIDTH, HEIGHT)
        self.flood_fill(grid, x, y-1, WIDTH, HEIGHT)
        self.flood_fill(grid, x, y+1, WIDTH, HEIGHT)