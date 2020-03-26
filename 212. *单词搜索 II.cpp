#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

// 使用了Leetcode 208. 实现 Trie (前缀树)中对前缀树的实现
class Trie {
private:
    Trie* next[26] = {nullptr}; // 26个字母
    bool is_end = false; // 标记是否单词结束
public:
    /** Initialize your data structure here. */
    Trie() {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* root = this;
        for(char c : word){
            if(root->next[c - 'a'] == nullptr){
                root->next[c - 'a'] = new Trie();
            }
            root = root->next[c - 'a'];
        }
        root->is_end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* root = this;
        for(char c : word){
            if(root->next[c - 'a'] == nullptr){
                return false;
            }
            root = root->next[c - 'a'];
        }
        return root->is_end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* root = this;
        for(char c : prefix){
            if(root->next[c - 'a'] == nullptr){
                return false;
            }
            root = root->next[c - 'a'];
        }
        return true; 
    }

    // 返回next，**因为是Trie*数组的首地址，指针的指针
    Trie** getnext(){
        return this->next;
    }
};

// 参考Leetcode 79. 单词搜索*
class Solution {
private:
    int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; //设置上下左右四个方向，简化代码
    vector<string> ans;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
        if(m == 0) return {};
        int n = board[0].size();

        // 建立前缀树
        Trie trie = Trie();
        for(string word : words){
            trie.insert(word);
        }

        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++){
                if(trie.getnext()[board[i][j] - 'a']){
                    string tmp(1, board[i][j]);
                    DFS(board, trie, i, j, tmp);
                }
            }
        }
        return ans;
    }

    void DFS(vector<vector<char>>& board, Trie& trie, int row, int column, string tmp){
        // 判断tmp是否在字典中，并且判断ans是否已经包含tmp
        if(trie.search(tmp)){
            bool flag = false;
            for(string each : ans){
                if(each == tmp){
                    flag = true;
                }
            }
            if(!flag) ans.push_back(tmp);
        }

        // 在79. 单词搜索*中使用了visited标记是否访问过某个字母，这里去掉了visited直接在原地修改
        char c = board[row][column];
        board[row][column] = '#';

        int x, y;
        for(int i = 0; i < 4; i ++){
            x = direction[i][0] + row;
            y = direction[i][1] + column;
            if(x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && board[x][y] != '#'){ //判断x，y是否合法
                if(trie.startsWith(tmp + board[x][y])){
                    DFS(board, trie, x, y, tmp + board[x][y]);
                }
            }
        }
        // 不要忘了还原
        board[row][column] = c;
    }
};