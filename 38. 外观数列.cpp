#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

// 这种字符串的题真不用啥算法
class Solution {
public:
    string countAndSay(int n) {
        string str = "1";
        while(--n){
            helper(str);
        }
        return str;
    }
    void helper(string& str){
        int len = str.size(), pos = 1;
        int cnt = 1; // 计数
        string tmp = str;
        str = "";
        while(pos < len){
            if(tmp[pos] == tmp[pos - 1]){
                cnt ++;
            }
            else{
                str += to_string(cnt) + tmp[pos - 1];
                cnt = 1;
            }
            pos++;
        }
        str += (to_string(cnt) + tmp[pos - 1]);
    }
};