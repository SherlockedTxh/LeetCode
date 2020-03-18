#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

// Trie 树的结点结构:
// Trie 树是一个有根的树，其结点具有以下字段：。
//     最多 R个指向子结点的链接，其中每个链接对应字母表数据集中的一个字母。
//         本文中假定 R 为 26，小写拉丁字母的数量。
//     布尔字段，以指定节点是对应键的结尾还是只是键前缀。

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
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */