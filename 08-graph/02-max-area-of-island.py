class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        num_rows = len(grid)
        num_cols = len(grid[0])
        max_area = 0

        def dfs(row: int, col: int):
            if row < 0 or col < 0 or row >= num_rows or col >= num_cols or grid[row][col] == 0:
                return 0
            
            grid[row][col] = 0

            return 1 + dfs(row - 1, col) + dfs(row + 1, col) + dfs(row, col - 1) + dfs(row, col + 1)
        
        for row in range(num_rows):
            for col in range(num_cols):
                if grid[row][col] == 1:
                    curr_area = dfs(row, col)
                    max_area = max(max_area, curr_area)

        return max_area