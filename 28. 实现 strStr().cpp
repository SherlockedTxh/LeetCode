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

// KMP模块化
class Solution {
public:
    vector<int> getNext(string t){
        vector<int> next(t.size());
        next[0] = -1;
        int i = 0, j = -1;
        while(i < t.size() - 1){
            if(j == -1 || t[i] == t[j]){
                i++;
                j++;
                next[i] = j;
            }
            else j = next[j];
        }
        return next;
    }

    int kmp(string s, string t){
        int i = 0, j = 0;
        vector<int> next = getNext(t);
        while(i < int(s.size()) and j < int(t.size())){ //这里不加int会有错，string.size()返回的是size_t类型，差错查的我吐了
            if(j == -1 or s[i] == t[j]){
                i++;
                j++;
            }
            else j = next[j];
        }
        if(j >= t.size()) return i - t.size();
        else return -1;
    }

    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0;
        return kmp(haystack, needle);
    }
};
