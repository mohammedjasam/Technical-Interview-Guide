/*
*
* Tag: Hash
* Time: O(nmlgm) where m is the average length of words.
* Space: O(nm)
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> anagramGroups;
        for(int i = 0; i < strs.size(); i ++){
            string tmp = strs[i];
            sort(tmp.begin(),tmp.end());
            anagramGroups[tmp].push_back(strs[i]);
        }
        
        vector<vector<string>> ans;
        for(auto it = anagramGroups.begin(); it != anagramGroups.end(); ++ it){
            ans.push_back(it->second);
        }
        
        return ans;
    }
};
