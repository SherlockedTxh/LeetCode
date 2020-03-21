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
    int strStr(string haystack, string needle) {
        int len1 = haystack.size(), len2 = needle.size();
        int pos = 0;
        if(len2 == 0) return 0;
        if(len1 == 0) return -1;
        while(pos <= len1 - len2){
            if(haystack[pos] == needle[0]){
                int tmp = 1;
                bool flag = true; 
                while(tmp < len2){
                    if(haystack[pos + tmp] == needle[tmp]){
                        tmp++;
                    }
                    else{
                        flag = false;
                        break;
                    }
                }
                if(flag) return pos;
            }
            pos++;
        }
        return -1;
    }
};