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
    int myAtoi(string str) {
        bool flag = false; // 未开始读取数字
        int sign = 1; // 正负号
        int ans = 0;
        for(char c : str){
            if(!flag){
                if(c == ' ') continue;
                else if(c == '+' || c == '-'){
                    flag = true;
                    if(c == '-') sign = -1;
                    continue;
                }
                else if(c - '0' >= 0 && c - '0' <= 9){
                    flag = true;
                    ans = c - '0';
                }
                else{
                    return 0;
                }
            }
            else{
                if(c - '0' >= 0 && c - '0' <= 9){
                    if(ans > INT_MAX / 10 || (ans == INT_MAX / 10 && (c - '0') % 10 > 7)) return INT_MAX;
                    if(ans < INT_MIN / 10 || (ans == INT_MIN / 10 && ('0' - c) % 10 <= -8)) return INT_MIN;
                    ans = ans * 10 + sign * (c - '0');
                }
                else{
                    break;
                }
            }
        }
        return ans;
    }
};

// 有限状态自动机
class Automaton {
    string state = "start";
    unordered_map<string, vector<string>> table = {
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end", "end", "end", "end"}}
    };

    int get_col(char c){
        if(isspace(c)) return 0;
        else if(c == '+' or c == '-') return 1;
        else if(isdigit(c)) return 2;
        return 3;
    }

public:
    int sign = 1;
    long long ans = 0;

    void get(char c){
        state = table[state][get_col(c)];
        if(state == "in_number"){
            ans = ans * 10 + c - '0';
            ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
        }
        else if(state == "signed"){
            sign = c == '+' ? 1: -1;
        }
    }
};

class Solution {
public:
    int myAtoi(string str) {
        Automaton automaton;
        for(char c : str) automaton.get(c);
        return automaton.sign * automaton.ans;
    }
};
