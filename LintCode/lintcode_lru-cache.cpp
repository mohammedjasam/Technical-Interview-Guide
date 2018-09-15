/*
*
* Tag: Data Structure (Hash)
* Time: Get: O(n); Set: O(n)
* Space: O(n)
*/
#include<list>

class LRUCache{
public:
    // @param capacity, an integer
    LRUCache(int capacity) {
        // write your code here
        this->cap = capacity;
    }
    
    // @return an integer
    int get(int key) {
        // write your code here
        if(cacheMap.find(key) != cacheMap.end()){
            int ans = cacheMap[key]->val;
            cachelist.splice(cachelist.begin(), cachelist, cacheMap[key]);
            cacheMap[key] = cachelist.begin();
            return ans;
        }else{
            return -1;
        }
    }

    // @param key, an integer
    // @param value, an integer
    // @return nothing
    void set(int key, int value) {
        // write your code here
        if(cacheMap.find(key) != cacheMap.end()){
            cacheMap[key]->val = value;
            cachelist.splice(cachelist.begin(), cachelist, cacheMap[key]);
            cacheMap[key] = cachelist.begin();
        }else{
            if(cachelist.size() == cap){
                cacheMap.erase(cachelist.back().key);
                cachelist.pop_back();
            }
            cachelist.push_front(Node(key, value));
            cacheMap[key] = cachelist.begin();
        }
    }
    
private:
    struct Node{
        int key, val;
        Node (int k, int v) :key(k), val(v) {}
    };
    list<Node> cachelist;
    unordered_map<int, list<Node>::iterator> cacheMap;
    int cap;
};
