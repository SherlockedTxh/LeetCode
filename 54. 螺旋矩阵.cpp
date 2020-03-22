#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

// 用visited标记是否访问，设置dir[4][2]依次为右下左上，当走到头时 di = (di + 1) % 4 控制方向，循环次数为m*n
class Solution {    
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        if(m == 0) return ans;
        int n = matrix[0].size();

        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // 右下左上
        vector<vector<bool>> visited = vector(m, vector<bool>(n));

        int x = 0, y = 0; // 当前坐标
        int di = 0; // 当前前进方向
        for(int i = 0; i < m * n; i++){
            ans.push_back(matrix[x][y]);
            visited[x][y] = true;
            int new_x = x + dir[di][0];
            int new_y = y + dir[di][1];
            if(new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && !visited[new_x][new_y]){
                x = new_x;
                y = new_y;
                continue;
            }
            else{
                di = (di + 1) % 4;
                x += dir[di][0];
                y += dir[di][1];
            }
        }

        return ans;
    }
};