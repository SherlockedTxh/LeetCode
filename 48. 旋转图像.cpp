#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

//先转置，再把每一行元素倒序
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int len = matrix[0].size();
        for(int i = 0; i < len; i++){
            for(int j = i; j < len ; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i = 0; i < len; i++){
            for(int j = 0; j < len / 2; j++){
                swap(matrix[i][j], matrix[i][len - j - 1]);
            }
        }
    }
};