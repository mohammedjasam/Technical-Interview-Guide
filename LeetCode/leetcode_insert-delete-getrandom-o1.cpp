/*
*
* Tag: Hash Table
* Time: O(1)
* Space: O(n)
*/
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand (time(NULL));
        st.clear();
        tot = 0;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(st.find(val) != st.end())
            return false;
        arr[++ tot] = val;
        st[val] = tot;
        return true;
    }
    
    /** Deletes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(st.find(val) == st.end())
            return false;
        st[arr[tot]] = st[val];
        swap(arr[st[val]], arr[tot --]);
        st.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return arr[rand()%tot + 1];
    }
    
private:
    unordered_map<int, int> st;
    int arr[10010], tot;
};
