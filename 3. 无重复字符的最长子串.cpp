//方法一 滑动窗口 时间复杂度 O(Nˆ2)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //s[start,end) 左包含 右不包含
        int start(0), end(0), len(0), ans(0);
        while(end < s.length()){
            for(int i = start; i < end; i ++){
                if(s[i] == s[end]){
                    start = i + 1;
                    len = end - start;
                    break;
                }
            }
            end ++;
            len ++;
            ans = max(len, ans);
        }
        return ans;
    }
};

//方法二 哈希表 时间空间复杂度 O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //s[start,end) 左包含 右不包含
        int start(0), end(0), len(0), ans(0);
        unordered_map<char, int> hash;
        while(end < s.length()){
            if(hash.find(s[end]) != hash.end() && hash[s[end]] >= start){
                //hash.end()是尾后指针，不是指向最后一个元素
                start = hash[s[end]] + 1;
                len = end - start;
            }
            hash[s[end]] = end;
            end ++;
            len ++;
            ans = max(len, ans);
        }
        return ans;
    }
};
