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

// 方法二：按层模拟
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return {};
        }
        int rows = matrix.size(), columns = matrix[0].size();
        vector<int> ans;
        int left = 0, right = columns - 1, top = 0, bottom = rows -1;
        while(left <= right and top <= bottom){
            for(int column = left; column <= right; column++){
                ans.push_back(matrix[top][column]);
            }
            for(int row = top + 1; row <= bottom; row++){
                ans.push_back(matrix[row][right]);
            }
            if(left < right and top < bottom){
                for(int column = right - 1; column > left; column--){
                    ans.push_back(matrix[bottom][column]);
                }
                for(int row = bottom; row > top; row--){
                    ans.push_back(matrix[row][left]);
                }
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        return ans;
    }
};
