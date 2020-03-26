#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

// 方法一 维护一个pos=最左边的0的下标，从左往右扫描到非0元素，与pos交换，更新pos
// pos的更新：从pos + 1开始到i的第一个0的下标
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        int pos = len; //最左边的0的下标
        for(int i = 0; i < len; i ++){
            if(nums[i] == 0) pos = min(pos, i);
            else if(pos < len){
                swap(nums[i], nums[pos]);
                int tmp = pos;
                pos = i;
                for(int j = tmp + 1; j < i; j ++){
                    if(nums[j] == 0) {
                        pos = min(pos, j);
                        break;
                    }
                }
            }
        }
    }
};

// 方法二 避免swap lastNonZeroIndex指向从前向后最后一个不为0的元素，i为遍历指针。
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        int LastNonZeroIndex = 0;
        for(int i = 0; i < len; i++){
            if(nums[i] != 0){
                nums[LastNonZeroIndex++] = nums[i];
                if(LastNonZeroIndex != i){
                    nums[i] = 0;
                }
            }
        }
    }
};

// 方法三 双指针
// 跟方法一相似，维护当前已处理的最右边的非0元素的下标，比方法一写起来简单
// 保证lastNonZeroFoundAt指向位置的左边都是非0元素
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++) {
            if (nums[cur] != 0) {
                swap(nums[lastNonZeroFoundAt++], nums[cur]);
            }
        }
    }
};
