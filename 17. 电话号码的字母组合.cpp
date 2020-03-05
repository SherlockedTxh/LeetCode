#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> dict = {
            "",
            "", "abc", "def",
            "ghi","jkl","mno",
            "pqrs","tuv","wxyz"
        };

        vector<string> str;
        if(digits.size() == 0) return str;
        string s;

        DFS(digits, 0, s, str, dict);
        return str;
    }

    void DFS(string digits, int pos, string& s, vector<string>& str, vector<string> dict){
        if(pos == digits.size()){
            str.push_back(s);
            return ; 
        }
        string tmp = dict[digits[pos] - '0'];
        for(int i = 0; i < tmp.size(); i++){
            s.push_back(tmp[i]);
            DFS(digits, pos + 1, s, str, dict);
            s.pop_back();
        }
    }
};