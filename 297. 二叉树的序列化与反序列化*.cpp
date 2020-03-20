#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 层次遍历 写字符串
// Note：由于c++没有spit函数，这里用了stringstream和getline()
// 在<string>中的getline函数有四种重载形式：
// istream& getline (istream&  is, string& str, char delim);
// istream& getline (istream&& is, string& str, char delim);
// istream& getline (istream&  is, string& str);
// istream& getline (istream&& is, string& str);
// 用法和上第一种类似，但是读取的istream是作为参数is传进函数的。读取的字符串保存在string类型的str中。
// 函数的变量：
// is    ：表示一个输入流，例如 cin。
// str   ：string类型的引用，用来存储输入流中的流信息。
// delim ：char类型的变量，所设置的截断字符；在不自定义设置的情况下，遇到’\n’，则终止输入。

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> myqueue;
        string str = "";
        myqueue.push(root);
        while(!myqueue.empty()){
            TreeNode* curr = myqueue.front();
            if(curr){
                str += to_string(curr->val) + ","; // , 分隔
                if(myqueue.empty() && !curr->left && !curr->right){
                    break;
                }
                myqueue.push(curr->left);
                myqueue.push(curr->right);
            }
            else{
                str += "#,"; // #表示null
            }
            myqueue.pop();
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream sstream;
        if(data == "#,") return nullptr;
        sstream << data; // 把data放入输入流中
        string tmp;
        vector<string> str_list;
        while(getline(sstream, tmp, ',')){ // 以,为分隔
            str_list.push_back(tmp);
        }

        queue<TreeNode*> myqueue;
        int len = str_list.size(), pos = 0;
        TreeNode* root = new TreeNode(stoi(str_list[pos++]));
        myqueue.push(root);
        while(!myqueue.empty()){
            TreeNode* curr = myqueue.front();
            myqueue.pop();
            if(str_list[pos] != "#"){
                curr->left = new TreeNode(stoi(str_list[pos]));
                myqueue.push(curr->left);
            }
            pos++;
            if(str_list[pos] != "#"){
                curr->right = new TreeNode(stoi(str_list[pos]));
                myqueue.push(curr->right);
            }
            pos++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));