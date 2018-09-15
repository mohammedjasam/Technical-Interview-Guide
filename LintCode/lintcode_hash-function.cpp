/*
*
* Tag: Hash
* Time: O(m) where m is the length of given string.
* Space: O(m)
*/
class Solution {
public:
    /**
     * @param key: A String you should hash
     * @param HASH_SIZE: An integer
     * @return an integer
     */
    int hashCode(string key,int HASH_SIZE) {
        // write your code here
        int hashval = 0;
        if(key.size() == 0)
            return hashval;
        vector<long long> fact(key.size());
        init(fact,HASH_SIZE);
        for(int i = 0; i < key.size(); ++ i){
            
            int val = (int)key[i], exp = key.size() - 1 - i;
            hashval += (val*fact[exp])%HASH_SIZE;
            hashval %= HASH_SIZE;
        }
        return hashval;
    }
    
    void init(vector<long long> &fact,int HASH_SIZE){
        fact[0] = 1;
        for(int i = 1; i < fact.size(); ++ i)
            fact[i] = (fact[i - 1]*33)%HASH_SIZE;
    }
};
