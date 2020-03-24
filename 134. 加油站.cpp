#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

// 如果 sum(gas) < sum(cost) ，那么不可能环行一圈，这种情况下答案是 -1 。
// 第二个规则可以被一般化，我们引入变量 curr_tank ，记录当前油箱里剩余的总油量。如果在某一个加油站 curr_tank比 0 小，意味着我们无法到达这个加油站。
// 初始化 total_tank 和 curr_tank 为 0 ，并且选择 0 号加油站为起点。
// 遍历所有的加油站：
// 每一步中，都通过加上 gas[i] 和减去 cost[i] 来更新 total_tank 和 curr_tank 。
// 如果在 i + 1 号加油站， curr_tank < 0 ，将 i + 1 号加油站作为新的起点，同时重置 curr_tank = 0 ，让油箱也清空。
// 如果 total_tank < 0 ，返回 -1 ，否则返回 starting station。

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int pos = 0, len = gas.size();
        int curr = 0, total = 0;
        
        for(int i = 0; i < len; i++){
            curr += gas[i] - cost[i];
            total += gas[i] - cost[i];
            if(curr < 0){
                curr = 0;
                pos = i + 1;
            }
        }
        return total >= 0 ? pos : -1;
    }
};

// 总油量剩余值最小处的索引为起点
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int pos = 0, len = gas.size();
        int spare = 0, minspare = INT_MAX;
        
        for(int i = 0; i < len; i++){
            spare += gas[i] - cost[i];
            if(spare < minspare){
                minspare = spare;
                pos = i;
            }
        }
        return spare >= 0 ? (pos + 1) % len : -1;
    }
};