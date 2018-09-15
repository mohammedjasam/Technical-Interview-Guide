/*
*
* Tag: Data Structure (Hash)
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    /**
     * @param s: a string represent DNA sequences
     * @return: all the 10-letter-long sequences 
     */
    vector<string> findRepeatedDna(string &s) {
        vector<string> ans;
        if(s.size() <= 10)
            return ans;
        unordered_map<string,int> dnaCnt;
        for(int i = 0; i + 9 < s.size(); ++ i){
            string curDNA = s.substr(i, 10);
            ++ dnaCnt[curDNA];
            if(dnaCnt[curDNA] == 2)
                ans.push_back(curDNA);
        }
        return ans;
    }
};
