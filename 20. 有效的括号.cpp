#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        if(s.size() == 0){
            return true;
        }
        for(int i = 0; i < s.size(); i ++){
            if(brackets.empty()){
                brackets.push(s[i]);
            } 
            else if(s[i] - brackets.top() == 2 || s[i] - brackets.top() == 1){
                brackets.pop();
            }
            else{
                brackets.push(s[i]);
            }
        }
        if(brackets.empty()){
            return true;
        } 
        else{
            return false;
        } 
    }
};