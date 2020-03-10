#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

//我首先想到的是DFS每次传入删掉使用过的元素后的vector，这种方法python很方便，但是C++里nums是引用，删除会改变nums，所以使用swap，
//下面是leetcode上的一个评论，解释的蛮详细的：
//好多人可能不太理解, 我自己的实现思路和上面的不太一样,下面给出理解: 
//这里换个角度去理解上面的回溯法就可以了, 首先想到的是数学的排列组合, N个元素有多少种排列方式呢, N*(N-1)*(N-2)..*(1), 
//这个式子我这样理解的, 第一个位置有N种选择, 第二个位置还有N-1种元素可选, 第三个位置还有N-2种元素可选,
//说到这里, 仔细看一下上面的回溯法, 只不过是将第n个位置的选择使用交换表示出来罢了, 
//比如说第一层计算,第一个位置可选1,2,3, 上面的算法就是通过交换,将1,2,3分别放在了第一个位置上, 
//第二个位置可选的元素是除了第一个位置的元素以外的其他所有元素, 则第二层做的事是将每个第一层计算来的结果第一个位置不变, 
//第二个位置通过交换获取到所有的N-1可选元素, 一直到第n层,就获取到了每个位置的所有可能性了, 本质上还是排列组合的
class Solution {
private:
    vector<vector<int>> ans;
public:
    void DFS(int start, vector<int>& nums){
        if(start == nums.size()){
            ans.push_back(nums);
        }
        else{
            for(int i = start; i < nums.size(); i ++){
                swap(nums[start], nums[i]);
                DFS(start + 1, nums);
                swap(nums[start], nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        DFS(0, nums);
        return ans;
    }
};
