#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos1 = 0, pos2 = 0, len = m;
        while(pos2 < n && pos1 < len){
            if(nums1[pos1] > nums2[pos2]){
                nums1.insert(nums1.begin() + pos1, nums2[pos2]);
                nums1.pop_back(); // insert之后删除最后一个元素
                pos2 ++;
                len ++;
            }
            pos1 ++;
        }
        while(pos2 < n){ // nums2没有扫描完，继续往nums1后面添加
            nums1[pos1++] = nums2[pos2++];
        }
        return;
    }
};

// 从后往前
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1, p2 = n - 1, p = m + n -1;
        while(p1 >= 0 and p2 >= 0){
            nums1[p--] = nums1[p1] > nums2[p2] ? nums1[p1--] : nums2[p2--];
        }
        while(p2 >= 0){
            nums1[p--] = nums2[p2--];
        }
    }
};
