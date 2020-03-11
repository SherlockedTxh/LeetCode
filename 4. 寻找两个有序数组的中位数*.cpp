class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int left1(0), right1, left2(0), right2, cnt(0); 
        double ans(0.0);
        right1 = (m + n + 1) / 2;
        right2 = (m + n + 2) / 2; //无论总数是奇数还是偶数，这两个位置的值求平均即可
        while(left1 < m && left2 < n){
            if(nums1[left1] < nums2[left2]){
                left1 ++;
                if(left1 + left2 == right1) ans += nums1[left1 - 1];
                if(left1 + left2 == right2){
                    ans += nums1[left1 - 1];
                    cnt = 1;
                    break;
                } 
            }
            else{
                left2 ++;
                if(left1 + left2 == right1) ans += nums2[left2 - 1];
                if(left1 + left2 == right2){
                    ans += nums2[left2 - 1];
                    cnt = 1;
                    break;
                } 
            }
        }
        //当一个数组已经走到头的情况
        if(left1 >= m && cnt == 0){
            while(left2 < n){
                left2 ++;
                if(left1 + left2 == right1) ans += nums2[left2 - 1];
                if(left1 + left2 == right2){
                    ans += nums2[left2 - 1];
                    cnt = 1;
                    break;
                } 
            }
        }
        else if(left2 >= n && cnt == 0){
            while(left1 < m){
                left1 ++;
                if(left1 + left2 == right1) ans += nums1[left1 - 1];
                if(left1 + left2 == right2){
                    ans += nums1[left1 - 1];
                    break;
                } 
            }
        }
        return ans/2;
    }
};
