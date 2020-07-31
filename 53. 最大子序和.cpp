#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0], sum = 0, len = nums.size();
        for(int i = 0; i < len; i++){
            sum = max(sum + nums[i], nums[i]);
            ans = max(ans, sum);
        }
        return ans;
    }
};

// 分治（线段树）
class Solution {
public:
    struct Status{
        int lsum, rsum, msum, isum;
    };
    Status pushup(Status l, Status r){
        int isum = l.isum + r.isum;
        int lsum = max(l.lsum, l.isum + r.lsum);
        int rsum = max(r.rsum, r.isum + l.rsum);
        int msum = max(max(l.msum, r.msum), l.rsum + r.lsum);
        Status a = {lsum, rsum, msum, isum};
        return a;
    }
    Status get(vector<int> &a, int l, int r){
        if(l == r) return Status{a[l], a[l], a[l], a[l]};
        int mid = (l + r) >> 1;
        Status left = get(a, l, mid);
        Status right = get(a, mid + 1, r);
        return pushup(left, right);
    }
    int maxSubArray(vector<int>& nums) {
        return get(nums, 0, nums.size() - 1).msum;
    }
};
