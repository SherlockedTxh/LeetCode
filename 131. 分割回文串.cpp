#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

// 回溯算法
// 从字符串 s ， start 位置（包括）开始， 逐个检查 sub ∈ s[start, end] 是否是回文字符串， 是则放入 tmp， 并递归， 
// 否则就进行回溯（递归返回上一层） sub ∈ s[start, end + 1] 是否是回文字符串, 如果是 ... ， 直到结束， 
// 如果发现 start == s.size() 说明 s 最后一个字符上一层检查定是回文串。 符合解

private:
    int size;
    vector<vector<string>> ans;
public:
    vector<vector<string>> partition(string s) {
        vector<string> tmp;
        size = s.size();
        backtrack(s, 0, tmp);
        return ans;
    }

    void backtrack(string& s, int start, vector<string>& tmp){
        if(start == size){
            ans.push_back(tmp);
            return;
        }
        for(int end = start; end < size; end++){
            if(check(s, start, end)){
                tmp.push_back(s.substr(start, end - start + 1));
                backtrack(s, end + 1, tmp);
                tmp.pop_back();
            }
        }
    }

    bool check(string& s, int start, int end){
        for(int i = start, j = end; i < j; i++, j--){
            if(s[i] != s[j]){
                return false;
            }
        }
        return true;
    }
};