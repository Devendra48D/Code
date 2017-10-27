"""
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
"""


class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        if matrix == []:
            return []
        rows = len(matrix)
        cols = len(matrix[0])
        row = 0
        col = 0
        ans = []
        while row < rows and col < cols:
            #print first row left to right
            for i in range(col, cols):
                ans.append(matrix[row][i])
            row += 1
            #print last column top-down
            for j in range(row, rows):
                ans.append(matrix[j][cols-1])
            cols -= 1
            if row < rows:
                #print last row right to left
                for k in range(cols-1, col-1, -1):
                    ans.append(matrix[rows-1][k])
                rows -= 1
            if col < cols:
                #print first column down to up
                for l in range(rows-1, row-1, -1):
                    ans.append(matrix[l][col])
                col += 1
        return ans
