# -*- encoding: utf-8 -*-
from collections import OrderedDict

# 从上面我们得到了解决这个问题的算法思维，但是会不会出现这个链表太长了，有上个几千、几万、几十万的链表单元，影响我们找不到结果呢？我们来考虑一下这个算法的规模。
# 首先，如果输入值为 int，那么能知道 int 最多也就是一个以 2 开头的 10 位的数字。接着我们来考虑这样一个问题，在 int 数据范围中，哪一个数字 n 它所对应的下一个数字 n 是最大的？
# 我们能构造得到 1 999 999 999，那么只有构造出 1 个 1 ，9 个 9 的数字在 int 范围内就是最大的，那么下一个节点时多少呢？根据快乐数的定义能得到 9×9×9+1=730，
# 那么 730 就是在整形范围之内任何一个数字所能映射到的下一个数字都不会超过 730，也就意味着当前所抽象出来的链表结构中节点数目最多不会超过 730 个，
# 如果快指针一次走两步、慢指针一次走一步的话，那么慢指针走的最多，也只不过走了 731×2=1462 步，而快指针就是走了 731 步。

class Solution:
    def isHappy(self, n: int) -> bool:
        myset = set()
        while n not in myset:
            myset.add(n)
            tmp = 0
            while(n):
                tmp += (n % 10)**2
                n //= 10
            n = tmp
        return 1 in myset

// 快慢指针
class Solution {
public:
    int getNext(int n){
        int total;
        while(n > 0){
            int d = n % 10;
            n /= 10;
            total += d * d;
        }
        return total;
    }

    bool isHappy(int n) {
        int slow = n, fast = getNext(n);
        while(fast != 1 and slow == fast){
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }
        return fast == 1;
    }
};
