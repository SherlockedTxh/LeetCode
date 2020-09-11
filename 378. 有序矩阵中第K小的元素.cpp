// 归并排序
// 一般归并排序是两个数组归并，而本题是 nn 个数组归并，所以需要用小根堆维护，以优化时间复杂度。
class Solution {
public:
    struct point{
        int val, x, y;
        point(){}
        point(int val, int x, int y) : val(val), x(x), y(y){}
        bool operator()(point a, point b){
            return a.val > b.val;
        }
    };
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<point, vector<point>, point> q;
        int n = matrix.size();
        for(int i = 0; i < n; i++){
            q.emplace(matrix[i][0], i, 0);
        }
        for(int i = 0; i < k - 1; i++){
            point now = q.top();
            q.pop();
            if(now.y != n - 1){
                q.emplace(matrix[now.x][now.y + 1], now.x, now.y + 1);
            }
        }
        return q.top().val;
    }
};

// 二分查找
class Solution {
   public:
    bool check(vector<vector<int>>& matrix, int mid, int k, int n) {
        int i = n - 1;
        int j = 0;
        int num = 0;
        while (i >= 0 && j < n) {
            if (matrix[i][j] <= mid) {
                num += i + 1;
                j++;
            } else {
                i--;
            }
        }
        return num >= k;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n - 1][n - 1];
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (check(matrix, mid, k, n)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
