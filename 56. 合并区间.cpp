#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
using namespace std;

//note: sort可以直接根据每个vector第一个元素排序，而不需要定义cmp
//思路：使用两个指针，对比前后两个区间：
// 1. if intervals[first][1] < intervals[next][0]:
//     前一个的右边界<后一个的左边界，存储first区间，first右移
// 2. else if intervals[first][1] >= intervals[next][1]:
//     前一个的右边界>=后一个的右边界，说明前一个包括了后一个，注意这里包括了first和next指向同一节点的情况,next右移
// 3. else if intervals[first][1] < intervals[next][1]:
//     前一个的右边界<后一个的右边界，更新first区间的右边界

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int len = intervals.size();
        if( len <= 1) return intervals;
        sort(intervals.begin(), intervals.end()); //sort根据每个vector第一个元素排序
        int first(0), next(0);
        vector<vector<int>> ans;
        while(next < len){
            if(intervals[first][1] < intervals[next][0]){
                ans.push_back(intervals[first]);
                first = next;
            }
            else if(intervals[first][1] >= intervals[next][1]){
                next ++;
            }
            else{
                intervals[first][1] = intervals[next][1];
            }
        }
        ans.push_back(intervals[first]);
        return ans;
    }
};