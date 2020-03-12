// 大致思路是把两个数组都划分成两部分，两个左边部分放在一起组成left，两个右边部分放在一起组成right，讨论当lefe和right数目相同时中位数的情况
// 这题需要好好想想才能理解，过程比较复杂，贴一个题解
// https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/xun-zhao-liang-ge-you-xu-shu-zu-de-zhong-wei-shu-b/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m > n) { // to ensure m<=n
            return findMedianSortedArrays(nums2, nums1);
        }
        int iMin = 0, iMax = m, halfLen = (m + n + 1) / 2;
        while(iMin <= iMax){
            int i = (iMin + iMax) / 2;
            int j = halfLen - i;
            if(i < iMax && nums2[j - 1] > nums1[i]){
                iMin = i + 1; // i is too small
            }
            else if(i > iMin && nums1[i - 1] > nums2[j]){
                iMax = i - 1; // i is too big
            }
            else{ // i is perfect
                int maxLeft = 0;
                if(i == 0) maxLeft = nums2[j - 1];
                else if(j == 0) maxLeft = nums1[i - 1];
                else maxLeft = max(nums1[i - 1], nums2[j - 1]);
                if((m + n) % 2 == 1) return maxLeft;

                int minRight = 0;
                if(i == m) minRight = nums2[j];
                else if(j == n) minRight = nums1[i];
                else minRight = min(nums1[i], nums2[j]);
                return (maxLeft + minRight) / 2.0;
            }
        }
        return 0.0;
    }
};

//原方法 复杂度O((m+n)/2)
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
