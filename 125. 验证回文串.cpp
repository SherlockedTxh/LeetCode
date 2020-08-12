#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

// 双指针 一趟写下来居然一个bug也没有直接击败98.62%/100%通过，可把我牛逼坏了，插会儿腰
class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.size();
        int left = 0, right = len - 1;
        while(left < right){
            if(check(s[left]) && check(s[right])){
                if(s[left] != s[right]){
                    return false;
                }
                left++;
                right--;
            }
            else if(!check(s[left]) && check(s[right])){
                left++;
            }
            else if(check(s[left]) && !check(s[right])){
                right--;
            }
            else{
                left++;
                right--;
            }
        }
        return true;
    }

    bool check(char& a){
        if((a >= 'a' && a <= 'z') || (a >= '0' && a <= '9')){
            return true;
        }
        else if((a >= 'A' && a <= 'Z')){
            a += 32;
            return true;
        }
        return false;
    }
};

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int left = 0, right = n - 1;
        while(left < right){
            while(left < right and !isalnum(s[left])) left++;
            while(left < right and !isalnum(s[right])) right--;
            if(left < right){
                if(tolower(s[left]) == tolower(s[right])){
                    left++;
                    right--;
                }
                else return false;
            }
        }
        return true;
    }
};
