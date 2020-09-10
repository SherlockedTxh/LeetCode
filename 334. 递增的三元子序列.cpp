class Solution {
public:
  bool increasingTriplet(vector<int>& nums) {
    int len = nums.size();
    if (len < 3) return false;
    int small = INT_MAX, mid = INT_MAX;
    for (auto num : nums) {
      if (num <= small) {
        small = num;
      } else if (num <= mid) {
        mid = num;
      } 
      else if (num > mid) {
        return true;
      }
    }
    return false;    
  }
};
