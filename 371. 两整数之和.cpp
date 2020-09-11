class Solution {
public:
    int getSum(int a, int b) {
        if(!(a&b)) return a ^ b;
        return getSum(a ^ b, (unsigned int)(a & b) << 1);
    }
};
