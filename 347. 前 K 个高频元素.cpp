// 小顶堆
// 首先遍历整个数组，并使用哈希表记录每个数字出现的次数，并形成一个「出现次数数组」。
// 找出原数组的前 kk 个高频元素，就相当于找出「出现次数数组」的前 kk 大的值。
class Solution {
public:
    struct cmp{
        bool operator()(pair<int, int> a, pair<int, int> b){
            return a.second > b.second;
        }
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(auto num : nums){
            freq[num]++;
        }

        // pair 的第一个元素代表数组的值，第二个元素代表了该值出现的次数
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> heapk;
        for(auto tmp : freq){
            if(heapk.size() == k){
                if(heapk.top().second < tmp.second){
                    heapk.pop();
                    heapk.push(make_pair(tmp.first, tmp.second));
                }
            }
            else{
                heapk.push(make_pair(tmp.first, tmp.second));
            }
        }
        vector<int> ans;
        while(!heapk.empty()){
            ans.push_back(heapk.top().first);
            heapk.pop();
        }
        return ans;
    }
};

// 快排
class Solution {
public:
    void qsort(vector<pair<int, int>>& v, int start, int end, vector<int>& ret, int k) {
        int picked = rand() % (end - start + 1) + start;
        swap(v[picked], v[start]);

        int pivot = v[start].second;
        int index = start;
        for (int i = start + 1; i <= end; i++) {
            if (v[i].second >= pivot) {
                swap(v[index + 1], v[i]);
                index++;
            }
        }
        swap(v[start], v[index]);

        if (k <= index - start) {
            qsort(v, start, index - 1, ret, k);
        } else {
            for (int i = start; i <= index; i++) {
                ret.push_back(v[i].first);
            }
            if (k > index - start + 1) {
                qsort(v, index + 1, end, ret, k - (index - start + 1));
            }
        }
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> occurrences;
        for (auto& v: nums) {
            occurrences[v]++;
        }

        vector<pair<int, int>> values;
        for (auto& kv: occurrences) {
            values.push_back(kv);
        }
        vector<int> ret;
        qsort(values, 0, values.size() - 1, ret, k);
        return ret;
    }
};
