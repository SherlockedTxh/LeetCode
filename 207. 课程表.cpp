#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

// 拓扑排序
// 本题可约化为： 课程安排图是否是有向无环图(DAG)。即课程间规定了前置条件，但不能构成任何环路，否则课程前置条件将不成立。
// 算法流程：
//     统计课程安排图中每个节点的入度，生成入度表indegrees。
//     借助一个队列 queue，将所有入度为0的节点入队。
//     当 queue 非空时，依次将队首节点出队，在课程安排图中删除此节点 pre：
//         并不是真正从邻接表中删除此节点 pre，而是将此节点对应所有邻接节点 cur 的入度减1
//         当入度减1后为0说明 cur 所有的前驱节点已经被 “删除”，此时将 cur 入队。
//     最后若所有节点都被“删除”，说明无环，反之有环

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegrees(numCourses);
        vector<vector<int>> adjacency(numCourses); // 邻接表
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
            cnt ++;
            myqueue.pop();
            for(int i = 0; i < adjacency[tmp].size(); i ++){
                indegrees[adjacency[tmp][i]] --; // 邻接表中每个节点入度减1
                if(indegrees[adjacency[tmp][i]] == 0){
                    myqueue.push(adjacency[tmp][i]); // 入度为0入队
                }
            }
        }
        return cnt == numCourses;
    }
};