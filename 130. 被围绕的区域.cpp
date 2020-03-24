#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

// dfs
// 处理边界上的O，寻找和边界联通的O，标记为'#'，其他O都被X包围，最后O转换为X，#转换为O即可，
class Solution {
private:
    int row, column;
public:
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0) return;
        this->row = board.size();
        this->column = board[0].size();

        for(int i = 0; i < row; i++){
            for(int j = 0; j < column; j++){
                bool isEdge = i == 0 || i == row - 1 || j == 0 || j == column - 1;
                if(isEdge && board[i][j] == 'O'){
                    dfs(board, i, j);
                }
            }
        }

        for(int i = 0; i < row; i++){
            for(int j = 0; j < column; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }

    void dfs(vector<vector<char>>& board, int x, int y){
        if(x < 0 || x >= row || y < 0 || y >= column || board[x][y] == 'X' || board[x][y] == '#'){
            return;
        }
        else{
            board[x][y] = '#';
            dfs(board, x - 1, y);
            dfs(board, x + 1, y);
            dfs(board, x, y - 1);
            dfs(board, x, y + 1);
        }
    }
};