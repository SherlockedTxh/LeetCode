#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

// 这个方法其实扫描了所次，官方题解是用了3个map实现了一次扫描
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool flag = true;
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    if(!isValid(board, i, j)){
                        return false;
                    }
                }
            }
        }
        return true;
    }

    bool isValid(vector<vector<char>>& board, int x, int y){
        // 判断当前位置是否合法
        for(int i = 0; i < 9 && i != y; i++){
            if(board[x][i] == board[x][y]) return false;
        }
        for(int i = 0; i < 9 && i != x; i++){
            if(board[i][y] == board[x][y]) return false;
        }
        int row = (x / 3) * 3, column = (y / 3) * 3; // 找到对应九宫格左上角坐标
        for(int i = row; i < row + 3; i++){
            for(int j = column; j < column + 3; j++){
                if(!(i == x && j == y)){
                    if(board[i][j] == board[x][y]) return false;
                }
            }
        }
        return true;
    }
};