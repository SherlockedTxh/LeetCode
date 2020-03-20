#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

// 使用 min(numRows,len(s)) 个列表来表示 Z 字形图案中的非空行。
// 从左到右迭代 s，将每个字符添加到合适的行。可以使用当前行和当前方向这两个变量对合适的行进行跟踪。
// 只有当我们向上移动到最上面的行或向下移动到最下面的行时，当前方向才会发生改变。

class Solution {
public:
    string convert(string s, int numRows) {

        if(numRows == 1) return s;

        vector<string>rows(min(size_t(numRows), s.size()));
        int curRow = 0;
        bool goingDown = true;

        for(char c : s){
            rows[curRow] += c;
            if(curRow == 0 || curRow == numRows - 1){
                goingDown = !goingDown;
            }
            curRow += goingDown ? -1 : 1;
        }

        string str;
        for(auto row : rows) str += row;
        return str;
    }
};