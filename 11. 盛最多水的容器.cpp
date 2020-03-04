#include <string>
#include <vector>
using namespace std;

//双指针，分别指向对头队尾，指针从较短边向较长边移动

class Solution {
public:
    int maxArea(vector<int>& height) {
        int start(0), end(height.size() - 1), maxarea = 0;
        while(start < end){
            maxarea = max(maxarea, min(height[start], height[end]) * (end - start));
            if(height[start] < height[end]){
                start ++;
            }
            else {
                end --;
            }
        }
        return maxarea;
    }
};
