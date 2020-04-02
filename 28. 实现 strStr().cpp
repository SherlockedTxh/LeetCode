#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

// 方法一：逐个匹配
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

// 方法二：KMP
class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.size(), len2 = needle.size();
        int j = 0, k = -1;
        if(len2 == 0) return 0;
        if(len1 == 0) return -1;
        vector<int> next = vector<int>(len2 + 1);
        next[0] = -1;
        while(j < len2){
            while(k >= 0 && needle[j] != needle[k]) k = next[k];
            j++;
            k++;
            next[j] = k;
        }

        int i = 0;
        j = 0;
        while(i < len1){
            while(j >= 0 && needle[j] != haystack[i]) j = next[j];
            i++;
            j++;
            if(j == len2){
                return i - j;
            }
        }
        return -1;
    }
};
