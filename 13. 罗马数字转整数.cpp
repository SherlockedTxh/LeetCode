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
    int romanToInt(string s) {
        unordered_map<char, int> value = {{'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}};
        int len = s.size(), ans = 0;
        for(int i = 0; i < len - 1; i++){
            if(s[i] == 'I' && (s[i + 1] == 'V' || s[i + 1] == 'X')){
                ans -= value[s[i]];
            }
            else if(s[i] == 'X' && (s[i + 1] == 'L' || s[i + 1] == 'C')){
                ans -= value[s[i]];
            }
            else if(s[i] == 'C' && (s[i + 1] == 'D' || s[i + 1] == 'M')){
                ans -= value[s[i]];
            }
            else{
                ans += value[s[i]];
            }
        }
        return ans + value[s[len - 1]];
    }
};

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string, int> m = {{"I", 1}, {"IV", 3}, {"IX", 8}, {"V", 5}, {"X", 10}, {"XL", 30}, {"XC", 80}, {"L", 50}, {"C", 100}, {"CD", 300}, {"CM", 800}, {"D", 500}, {"M", 1000}};
        int r = m[s.substr(0, 1)];
        for(int i=1; i<s.size(); ++i){
            string two = s.substr(i-1, 2);
            string one = s.substr(i, 1);
            r += m[two] ? m[two] : m[one];
        }
        return r;
    }
};