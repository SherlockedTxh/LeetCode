#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

//回溯法，方法不难想，但是代码不是特别好写，总有些小错误
class Solution {
private:
    int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; //设置上下左右四个方向，简化代码
public:
    bool DFS(vector<vector<char>>& board, string word, vector<vector<bool>>& visited, int row, int column, int index){
        if(index == word.size() - 1){
            return word[index] == board[row][column];
        }
        if(word[index] == board[row][column]){
            visited[row][column] = true;
            int x, y;
            for(int i = 0; i < 4; i ++){
                x = direction[i][0] + row;
                y = direction[i][1] + column;
                if(x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && !visited[x][y]){ //判断x，y是否合法
                    if(DFS(board, word, visited, x, y, index + 1)){
                        return true;
                    }
                }
            }
            visited[row][column] = false; // 不要忘记搜索后重置visited
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        if(m == 0) return false;
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));

        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++){
                if(DFS(board, word, visited, i, j, 0)){ //当搜索到结果返回true，避免继续搜索
                    return true;
                }
            }
        }
        return false;
    }
};