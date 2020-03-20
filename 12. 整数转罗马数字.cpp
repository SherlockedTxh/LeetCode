#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

// 贪心 面值思想
class Solution {
public:
    string intToRoman(int num) {
        int nums[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string romans[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        string str;
        int index = 0;
        while(index < 13){ // 这里共13种符号
            if(num - nums[index] >=0){
                str += romans[index];
                num -= nums[index];
            }
            else{
                index ++;
            }
        }
        return str;
    }
};