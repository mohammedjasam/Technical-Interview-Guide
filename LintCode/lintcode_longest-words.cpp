/*
*
* Tag: Data Structure (Hash)
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    /**
     * @param dictionary: a vector of strings
     * @return: a vector of strings
     */
    vector<string> longestWords(vector<string> &dictionary) {
        // write your code here
        vector<string> ans;
        if(!dictionary.size())
            return ans;
        int len = 0, cnt = 0, n = dictionary.size();
        for(int i = 0; i < n; ++ i){
            if(len < dictionary[i].size()){
                len = dictionary[i].size();
                cnt = 1;
            }else if(len == dictionary[i].size()){
                ++ cnt;
            }
        }
        ans.resize(cnt);
        int id = 0;
        for(int i = 0; i < n; ++ i){
            if(len == dictionary[i].size()){
                ans[id ++] = dictionary[i];
            }
        }
        return ans;
    }
};
