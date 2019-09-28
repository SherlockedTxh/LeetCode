class Solution(object):
    def totalNQueens(self, n):
        """
        :type n: int
        :rtype: int
        """
        
        board = ["." * n for _ in range(n)]

        res = []

        def checkRowAndCol(row,col):
            for i in range(n):
                if(board[row][i] == "Q" and i != col) or (board[i][col] == "Q" and i != row):
                    return False
            return True
        
        def checkDiagonals(row,col):
            add = row + col
            sub = col -row
            for x in range(n):
                if x == row:
                    continue
                y = add - x
                if y >= 0 and y < n and x >= 0 and x < n and board[x][y] == "Q": #发生/冲突
                    return False
            
                y = sub + x
                if y >= 0 and y < n and x >= 0 and x < n and board[x][y] == "Q": #发生\冲突
                    return False
            return True

        def dfs(row,col):
            if col >= n:
                return
            board[row] = "." * col + "Q" + (n - col - 1) * "."
            if checkDiagonals(row,col) and checkRowAndCol(row,col):
                if row == n - 1:
                    res.append(board)
                else :
                    for i in range(n):
                        dfs(row+1,i)
            
            board[row] = "." * n
            return 

        for i in range(n):
            dfs(0,i)

        return len(res)