#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
#include <utility>
using namespace std;

// 算法

// 对给定的 wordList 做预处理，找出所有的通用状态。将通用状态记录在字典中，键是通用状态，值是所有具有通用状态的单词。

// 将包含 beginWord 和 1 的元组放入队列中，1 代表节点的层次。我们需要返回 endWord 的层次也就是从 beginWord 出发的最短距离。

// 为了防止出现环，使用访问数组记录。

// 当队列中有元素的时候，取出第一个元素，记为 current_word。

// 找到 current_word 的所有通用状态，并检查这些通用状态是否存在其它单词的映射，这一步通过检查 all_combo_dict 来实现。

// 从 all_combo_dict 获得的所有单词，都和 current_word 共有一个通用状态，所以都和 current_word 相连，因此将他们加入到队列中。

// 对于新获得的所有单词，向队列中加入元素 (word, level + 1) 其中 level 是 current_word 的层次。

// 最终当你到达期望的单词，对应的层次就是最短变换序列的长度。

// bfs
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int len = beginWord.size();

        // 对WordList进行预处理，找出所有的通用状态。将通用状态记录在字典中，键是通用状态，值是所有具有通用状态的单词。
        unordered_map<string,vector<string>> allComboDict;
        for(auto word : wordList){
            for(int i = 0; i < len; i++){
                string newword = word.substr(0, i) + '*' + word.substr(i + 1, len - i - 1);
                allComboDict[newword].push_back(word);
            }
        }

        // bfs
        queue<pair<string,int>> que;
        que.push(make_pair(beginWord, 1));

        // visited记录已经访问过的单词
        unordered_map<string, bool> visited;
        visited[beginWord] = true;

        while(!que.empty()){
            auto node = que.front();
            que.pop();
            int level = node.second;
            for(int i = 0; i < len; i++){
                // 生成当前单词的所有通用状态
                string newword = node.first.substr(0, i) + '*' + node.first.substr(i + 1, len - i - 1);
                if(allComboDict.find(newword) != allComboDict.end()){
                    // 如果该通用状态在allComboDict中，比较其对应的vector中是否存在endWord
                    for(string adjacentWord : allComboDict[newword]){
                        if(adjacentWord == endWord){
                            return level + 1;
                        }
                        // 在visited中记录以访问的单词
                        if(visited.find(adjacentWord) == visited.end()){
                            visited[adjacentWord] = true;
                            que.push(make_pair(adjacentWord, level + 1));
                        }
                    }
                }
            }
        }

        return 0;
    }
};

// 双向BFS
// 算法与之前描述的标准广搜方法相类似。

// 唯一的不同是我们从两个节点同时开始搜索，同时搜索的结束条件也有所变化。

// 我们现在有两个访问数组，分别记录从对应的起点是否已经访问了该节点。

// 如果我们发现一个节点被两个搜索同时访问，就结束搜索过程。因为我们找到了双向搜索的交点。过程如同从中间相遇而不是沿着搜索路径一直走。
//    双向搜索的结束条件是找到一个单词被两边搜索都访问过了。

// 最短变换序列的长度就是中间节点在两边的层次之和。因此，我们可以在访问数组中记录节点的层次。

// https://leetcode-cn.com/problems/word-ladder/solution/dan-ci-jie-long-by-leetcode/

class Solution {
private:
    int len;
    unordered_map<string,vector<string>> allComboDict;
    int visitWordNode(queue<pair<string, int>>& que, unordered_map<string, int>& visited, unordered_map<string, int>& othersVisited){
        auto node = que.front();
        que.pop();
        int level = node.second;
        for(int i = 0; i < this->len; i++){
            string newword = node.first.substr(0, i) + '*' + node.first.substr(i + 1, this->len - i - 1);
            if(this->allComboDict.find(newword) != this->allComboDict.end()){
                for(string adjacentWord : this->allComboDict[newword]){
                    if(othersVisited.count(adjacentWord)){
                        return level + othersVisited[adjacentWord];
                    }
                    if(visited.find(adjacentWord) == visited.end()){
                        visited[adjacentWord] = level + 1;
                        que.push(make_pair(adjacentWord, level + 1));
                    }
                }
            }
        }
        return -1;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool flag = false;
        for(string word : wordList){
            if(word == endWord){
                flag = true;
                break;
            }
        }
        if(!flag) return 0;

        this->len = beginWord.size();

        for(string word : wordList){
            for(int i = 0; i < this->len; i++){
                string newword = word.substr(0, i) + '*' + word.substr(i + 1, this->len - i - 1);
                this->allComboDict[newword].push_back(word);
            }
        }

        queue<pair<string,int>> que_begin, que_end;
        que_begin.push(make_pair(beginWord, 1));
        que_end.push(make_pair(endWord, 1));

        unordered_map<string, int> visitedBegin, visitedEnd;
        visitedBegin[beginWord] = 1;
        visitedEnd[endWord] = 1;

        while(!que_begin.empty() && !que_end.empty()){
            int ans = visitWordNode(que_begin, visitedBegin, visitedEnd);
            if (ans > -1) {
                return ans;
            }

            ans = visitWordNode(que_end, visitedEnd, visitedBegin);
            if (ans > -1) {
                return ans;
            }
        }
        return 0;
    }
};