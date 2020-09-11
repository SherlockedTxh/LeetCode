class Solution {
    vector<int> nums;
    vector<int> copy;
public:
    Solution(vector<int>& nums) {
        this->nums = nums;
        this->copy = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        nums = copy;
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for(int i=nums.size() - 1; i>=0; i--) {
            int rd = rand() % (i + 1);          
            swap(nums[rd], nums[i]);            
        }
        return nums;
    }
};
