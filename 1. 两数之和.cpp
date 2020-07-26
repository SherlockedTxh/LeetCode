// 哈希表
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap = unordered_map<int, int>();
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            if(hashmap.find(target - nums[i]) != hashmap.end()){
                ans.push_back(i);
                ans.push_back(hashmap[target - nums[i]]);
                break;
            }
            else{
                hashmap[nums[i]] = i;
            }
        }
        return ans;
    }
};
