#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

// 算法 挺巧妙的 我没想出来
// 遍历整个矩阵，如果 cell[i][j] == 0 就将第 i 行和第 j 列的第一个元素标记。
// 第一行和第一列的标记是相同的，都是 cell[0][0]，所以需要一个额外的变量告知第一列是否被标记，同时用 cell[0][0] 继续表示第一行的标记。
// 然后，从第二行第二列的元素开始遍历，如果第 r 行或者第 c 列被标记了，那么就将 cell[r][c] 设为 0。这里第一行和第一列的作用就相当于方法一中的 row_set 和 column_set 。
// 然后我们检查是否 cell[0][0] == 0 ，如果是则赋值第一行的元素为零。
// 然后检查第一列是否被标记，如果是则赋值第一列的元素为零。

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if(row == 0) return;
        int column = matrix[0].size();

        bool isCol = false;
        for(int i = 0; i < row; i++){
            if(matrix[i][0] == 0){
                isCol = true;
            }
            for(int j = 1; j < column; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int i = 1; i < row; i++){
            for(int j = 1; j < column; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        if(matrix[0][0] == 0){
            for(int i = 1; i < column; i++){
                matrix[0][i] = 0;
            }
        }

        if(isCol){
            for(int i = 0; i < row; i++){
                matrix[i][0] = 0;
            }
        }
    }
};