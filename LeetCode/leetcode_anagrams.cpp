/*
* Algorithm: Hash, Brute force
* Time complexity: O(n)
* Memory complexity: O(n)
*/
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string,vector<string> > key;
        for(int i = 0; i < strs.size(); i ++){
            string tmp = strs[i];
            sort(tmp.begin(),tmp.end());
            key[tmp].push_back(strs[i]);
        }
        
        vector<string> ans;
        for(auto it = key.cbegin(); it != key.cend(); it ++){
            if(it->second.size() > 1)
                ans.insert(ans.end(), it->second.begin(), it->second.end());
        }
        return ans;
    }
};

