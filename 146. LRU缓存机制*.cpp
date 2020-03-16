#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
#include <unordered_set>
#include <list>
using namespace std;

// 这题蛮难的，感觉不应该是中等
// 有一种叫做有序字典的数据结构，综合了哈希表和链表，在 Python 中为 OrderedDict，在 Java 中为 LinkedHashMap。
// 这里用的方法是哈希表加上双向链表，C++中list就是用双向链表实现的，跟vector的区别如下：
// vector:
//   vector与数组类似，拥有一段连续的内存空间，并且起始地址不变。便于随机访问，时间复杂度为O（1），
//   但因为内存空间是连续的，所以在进入插入和删除操作时，会造成内存块的拷贝，时间复杂度为O（n）。
//   此外，当数组内存空间不足，会采取扩容，通过重新申请一块更大的内存空间进行内存拷贝。
// List:
//   list底层是由双向链表实现的，因此内存空间不是连续的。根据链表的实现原理，List查询效率较低，时间复杂度为O（n），
//   但插入和删除效率较高。只需要在插入的地方更改指针的指向即可，不用移动数据。
class LRUCache {
private:
    queue<int> lru;
    int capacity; //缓存容量
    list<pair<int, int>> cache; // 双向链表：装着 (key, value) 元组
    unordered_map<int, list<pair<int, int>>::iterator> hashmap; // 哈希表：key 映射到 (key, value) 在 cache 中的位置
                                                                // 使用了迭代器
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        auto it = hashmap.find(key);
        if(it == hashmap.end()) return -1;
        pair<int, int> tmp = *hashmap[key]; //注意hashmap[key]是迭代器，类似指针，*迭代器名就表示迭代器指向的元素
        cache.erase(hashmap[key]);
        cache.push_front(tmp);
        hashmap[key] = cache.begin(); // 更新 (key, value) 在 cache 中的位置
        return tmp.second;
    }
    
    void put(int key, int value) {
        auto it = hashmap.find(key);
        if(it != hashmap.end()){ // key 存在，更改 value 并换到队头
            cache.erase(hashmap[key]);
            cache.push_front(make_pair(key, value));
            hashmap[key] = cache.begin();
            return;
        }
        else if(cache.size() == capacity){ // cache 已满，删除尾部的键值对，ache 和 map 中的数据都要删除
            auto tmp = cache.back();
            hashmap.erase(tmp.first);
            cache.pop_back();
        }
        cache.push_front(make_pair(key, value)); // 添加
        hashmap[key] = cache.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
