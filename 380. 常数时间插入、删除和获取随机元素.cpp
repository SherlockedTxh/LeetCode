// 哈希表 + 数组
// 将要删除的数字和数组的最后一个数字调换个位置，然后修改对应的 HashMap 中的值，这样只需要删除数组的最后一个元素即可，保证了常数时间内的删除
class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> index;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(index.count(val)) return false;
        nums.push_back(val);
        index[val] = nums.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(!index.count(val)) return false;
        int last = nums.back();
        index[last] = index[val];
        nums[index[val]] = last;
        nums.pop_back();
        index.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};
