/*
*
* Tag: Hash
* Time: O(nm) where n is the number of strings and m is the average length of those strings.
* Space: O(nm)
*/

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> ans;
        if(!strings.size()){
            return ans;
        }
        
        unordered_map<string, vector<string>> dict;
        for(int i = 0; i < strings.size(); ++ i){
            string t = strings[i];
            int dis = t[0] - 'a';
            for(int j = 0; j < t.size(); ++ j){
                if(t[j] - dis - 'a' >= 0)
                    t[j] = t[j] - dis;
                else
                    t[j] = (t[j] - dis) + 26;
            }
            
            dict[t].push_back(strings[i]);
        }
        
        for(auto it = dict.begin(); it != dict.end(); ++ it){
            ans.push_back(it->second);
        }
        
        return ans;
    }
};
