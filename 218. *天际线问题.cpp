#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
#include <set>
using namespace std;

// 扫描法
// https://leetcode-cn.com/problems/the-skyline-problem/solution/218tian-ji-xian-wen-ti-sao-miao-xian-fa-by-ivan_al/
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        multiset<pair<int, int>> allpoints;
        vector<vector<int>> ans;

        for(auto tmp : buildings){
            allpoints.insert(make_pair(tmp[0], -tmp[2])); // 左断点高度设置为负值，以此标记
            allpoints.insert(make_pair(tmp[1], tmp[2]));
        }

        multiset<int> heights({0}); // 保存当前位置所有高度。
        vector<int> last = {0, 0}; // 保存上一个位置的横坐标以及高度

        for(auto p : allpoints){
            if(p.second < 0) heights.insert(-p.second); // 如果是左端点 入堆
            else heights.erase(heights.find(p.second)); // 如果是右端点 出堆

            // 当前关键点，最大高度
            int maxHeight = *heights.rbegin(); // rbegin()返回一个逆向迭代器，指向逆向迭代的第一个元素

            // 当前最大高度如果不同于上一个高度，说明这是一个转折点
            if(last[1] != maxHeight){
                // 更新 last，并加入结果集
                last[0] = p.first;
                last[1] = maxHeight;
                ans.push_back(last);
            }
        }
        return ans;
    }
};