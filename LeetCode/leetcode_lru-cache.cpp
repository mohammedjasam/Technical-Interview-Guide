/*
*
* Tag: Data Structure
* Time: Get: O(1); Put: O(1)
* Space: O(n)
*/
class LRUCache {
private:
    unordered_map<int,list<pair<int,int>>::iterator> dictionary;
    list<pair<int,int>> cache;
    int capacity;
public:
    LRUCache(int _capacity) {
        dictionary.clear();
        capacity = _capacity;
    }
    
    int get(int key) {
        if(dictionary.count(key) == 0){
            return -1;
        }
        
        auto it = dictionary[key];
        int value = it->second;
        
        cache.erase(it);
        cache.push_front(make_pair(key, value));
        dictionary[key] = cache.begin();
        
        return value;
    }
    
    void put(int key, int value) {
        if(dictionary.count(key) == 0){
            while(cache.size() >= capacity){
                dictionary.erase(cache.back().first);
                cache.pop_back();
            }
        } else {
            cache.erase(dictionary[key]);
        }
        
        cache.push_front(make_pair(key, value));
        dictionary[key] = cache.begin();
        return ;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
