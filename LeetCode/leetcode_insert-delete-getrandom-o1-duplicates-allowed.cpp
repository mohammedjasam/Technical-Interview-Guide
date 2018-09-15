/*
*
* Tag: Data Structure
* Time: O(1)
* Space: O(n)
*/
class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        srand (time(NULL));
        tot = 0;
        dict.clear();
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        puts("1");
        bool res = dict.find(val) == dict.end();
        cache[++ tot] = val;
        dict[val].insert(tot);
        return res;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        puts("2");
        if(dict.find(val) == dict.end() || dict[val].size() == 0)
            return false;
        int posv = *(dict[val].begin()), nval = cache[tot];
        if(nval == val){
            dict[val].erase(tot);
            --tot;
            return true;
        }
        dict[val].erase(posv);
        dict[nval].erase(tot);
        dict[nval].insert(posv);
        swap(cache[posv], cache[tot]);
        -- tot;
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        puts("3");
    //    printf(" tot = %d\n",tot);
        return cache[rand()%tot + 1];
    }
private:
    unordered_map<int,unordered_set<int>> dict;
    int cache[100010], tot;
};
