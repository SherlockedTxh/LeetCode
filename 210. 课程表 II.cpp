#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <limits>
using namespace std;

// 与leetcode 207几乎一样，多了一个输出课程表
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegrees(numCourses);
        vector<vector<int>> adjacency(numCourses); // 邻接表
        vector<int> ans;
        int num = prerequisites.size();
        for(int i = 0; i < num; i ++){
            indegrees[prerequisites[i][0]] ++;
            adjacency[prerequisites[i][1]].push_back(prerequisites[i][0]); // 存边
        }
        queue<int> myqueue;
        for(int i = 0; i < numCourses; i ++){
            if(indegrees[i] == 0){
                myqueue.push(i); // 入度为0入队
            }
        }
        int cnt = 0;
        while(!myqueue.empty()){
            int tmp = myqueue.front();
            ans.push_back(tmp);
            cnt ++;
            myqueue.pop();
            for(int i = 0; i < adjacency[tmp].size(); i ++){
                indegrees[adjacency[tmp][i]] --; // 邻接表中每个节点入度减1
                if(indegrees[adjacency[tmp][i]] == 0){
                    myqueue.push(adjacency[tmp][i]);
                }
            }
        }
        return cnt == numCourses ? ans : vector<int>();
    }
};