#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

class Solution {
private:
    vector<int> candidates;
    vector<vector<int>> ans;
    vector<int> path;
public:
    void DFS(int start, int target){ //start为上一个已选值的索引,target为目标值减去已选值之和
        if(target == 0){
            ans.push_back(path);
            return;
        }
        for(int i = start; i < candidates.size(); i ++){
            if(target - candidates[i] >= 0){
                path.push_back(candidates[i]);
                DFS(i, target - candidates[i]);
                path.pop_back(); //DFS后path弹出最后一个元素
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        this->candidates = candidates;
        DFS(0, target);
        return ans;
    }
};