#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

// dfs 过不了 还不如两个for循环。。
class Solution {
public:
    bool dfs(vector<vector<int>>& matrix, int target, int x, int y){
        if(matrix[x][y] == target){
            return true;
        }
        bool right = false, down = false;
        if(x < matrix.size() - 1) right = dfs(matrix, target, x + 1, y);
        else right = false;
        if(y < matrix[0].size() - 1) down = dfs(matrix, target, x, y + 1);
        else down = false;
        return right | down;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if(row == 0) return false;
        int column = matrix[0].size();
        return dfs(matrix, target, 0, 0);
    }
};

// 对角线 二分查找 没有写

// 从左下角或者右上角出发搜索 很精妙！
// 算法：
// 首先，我们初始化一个指向矩阵左下角的 (row，col) 指针。
// 然后，直到找到目标并返回 true（或者指针指向矩阵维度之外的 (row，col) 为止，我们执行以下操作：
// 如果当前指向的值大于目标值，则可以 “向上” 移动一行。 
// 否则，如果当前指向的值小于目标值，则可以移动一列。
// 不难理解为什么这样做永远不会删减正确的答案；因为行是从左到右排序的，所以我们知道当前值右侧的每个值都较大。 
// 因此，如果当前值已经大于目标值，我们知道它右边的每个值会比较大。
// 也可以对列进行非常类似的论证，因此这种搜索方式将始终在矩阵中找到目标（如果存在）。
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if(row == 0) return false;
        int column = matrix[0].size();

        int x = row - 1, y = 0; // 左下角
        while(x >= 0 && y < column){
            if(matrix[x][y] == target){
                return true;
            }
            else if(matrix[x][y] > target){
                x --;
            }
            else{
                y ++;
            }
        }
        return false;
    }
};
