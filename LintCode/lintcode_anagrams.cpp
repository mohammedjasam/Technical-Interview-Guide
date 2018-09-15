/*
*
* Tag: Hash
* Time: O(nmlgm)
* Space: O(nm)
*/
class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        // write your code here
        vector<string> ans;
        if(strs.size() == 0)
            return ans;
        unordered_map<string, vector<string>> dic;
        int len = 1;
        for(int i = 0; i < strs.size(); ++ i){
            string val = strs[i];
            sort(val.begin(), val.end());
            if(dic.find(val) == dic.end()){
                vector<string> tmpval;
                tmpval.push_back(strs[i]);
                dic[val] = tmpval;
            }else
                dic[val].push_back(strs[i]);
        }
        for(unordered_map<string, vector<string>>::iterator it = dic.begin(); it != dic.end(); ++ it){
            vector<string> tmpans = it->second;
            if(tmpans.size() > len){
                for(int i = 0; i < tmpans.size(); ++ i)
                    ans.push_back(tmpans[i]);
            }
        }
        return ans;
    }
};

