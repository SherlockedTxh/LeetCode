#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
using namespace std;

//一个思路是质数相乘，但是那样很容易溢出
//下面用的方法是对每个字符串排序，字母异位词排序后结果相同
//建立一个map，排序后的字符串作为key，所有字母异位词组成的列表作为value
//复习了unordered_map的用法

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        vector<vector<string>> ans;
        for(int i = 0; i < strs.size(); i++){
            string tmp = strs[i];
            sort(strs[i].begin(), strs[i].end());
            hash[strs[i]].push_back(tmp);
        }
        for(auto it : hash){
            ans.push_back(it.second); //it.second访问value
        }
        return ans;
    }
};