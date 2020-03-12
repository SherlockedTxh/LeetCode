#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> dic, window;
        for(char c : t) dic[c]++;
        int left = 0, start = 0; // start记录s中已匹配字符串的开始位置
        int minLen = s.size() + 1;
        int cnt = 0; // cnt表示已匹配的字符总数
        for(int i = 0; i < s.size(); i ++){
            if(dic[s[i]]-- > 0 ) cnt ++; // 如果t中有当前字符，则cnt++,map中对应的值减1,可能是负值
            while(cnt == t.size()){ //cnt == t的长度，说明窗口已覆盖t
                if(minLen > i - left + 1){
                    minLen = i - left + 1;
                    start = left;
                }
                if(++dic[s[left]] > 0) cnt --; // left指针开始右移，经过的字符在map中对应的值加1，
                                               // 当dic[s[left]]>0,窗口去掉left指向的字符后已经不覆盖t了
                left ++;
            }
        }
        return minLen == s.size() + 1 ? "" : s.substr(start, minLen);
    }
};