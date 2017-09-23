#valid cell is a cell within range and not visited and which is 1 or land
def is_valid(r, c, grid, visited):
    rows = len(grid)
    cols = len(grid[0])
    return r >= 0 and r < rows and c >= 0 and c < cols and (not visited[r][c]) and grid[r][c] == '1'

#check all 4 neighboring cells and for each valid cell, check all of its neighbors as well
def dfs(row, col, grid, visited):
    visited[row][col] = True
    tocheck = [[-1, 0], [1, 0], [0, 1], [0, -1]]
    for offset in tocheck:
        r = row + offset[0]
        c = col + offset[1]
        if is_valid(r,c,grid, visited):
            dfs(r, c, grid, visited)



def numIslands(grid):
   """
   :type grid: List[List[str]]
   :rtype: int
   """
   #empty or not a grid, return 0
   if grid == [] or not grid:
       return 0
   rows = len(grols = len(grid[0])
   count = 0
   #visited 2d array
   visited = [[False for a in range(cols)] for b in range(rows)]
   for row in range(rows):
       for col in range(cols):
           #if a particular cell is 1, find all of its connectors and visit them 
           if grid[row][col] == '1' and not visited[row][col]:
               count += 1 
               dfs(row, col, grid, visited)
   return count
