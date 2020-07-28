#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

// 维护一个pos，当前关注的字母的下标
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int pos = -1;
        bool flag = true;
        string ans = "";
        if(strs.size() == 0) return ans;
        while(flag && pos < (int(strs[0].size()) - 1)){ // 不用int转型就有问题，string.size()返回size_t类型
            pos++;
            for(string str : strs){
                if(pos >= str.size() || str[pos] != strs[0][pos]){
                    flag = false;
                    break;
                }
            }
            if(flag) ans += strs[0][pos];
        }
        return ans;
    }
};

// 纵向扫描
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        int len = strs[0].size(), count = strs.size();
        for(int i = 0; i < len; i++){
            char c = strs[0][i];
            for(int j = 1; j < count; j++){
                if(i == strs[j].size() or strs[j][i] != c){
                    return strs[0].substr(0, i + 1);
                }
            }
        }
        return strs[0];
    }
};
