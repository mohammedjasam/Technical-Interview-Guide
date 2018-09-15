/*
*
* Tag: Hash
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    /*
     * @param s: a string
     * @param p: a string
     * @return: a list of index
     */
    vector<int> findAnagrams(string &s, string &p) {
        vector<int> ans;
        if(isSubstringAnagramsNotExist(s, p))
            return ans;
        vector<int> anagram_p(26, 0), anagram_s(26, 0);
        createAnagramOfSubString(anagram_p, p, p.size());
        createAnagramOfSubString(anagram_s, s, p.size());
        
        for(int l_bnd = 0, r_bnd = p.size(); r_bnd <= s.size(); ++ l_bnd, ++ r_bnd){
            if(isSameAnagrams(anagram_p, anagram_s)){
                ans.push_back(l_bnd);
            }
            updateAnagramOfStringWithGivenRange(anagram_s, s, l_bnd, r_bnd);
        }
        
        return ans;
    }
private:
    bool isSubstringAnagramsNotExist(string &s, string &p){
        return s.size() < p.size();
    }

    inline void createAnagramOfSubString(vector<int> &anagram_str, string &s, int s_size){
        for(int i = 0; i < s_size; ++ i)
            ++ anagram_str[(s[i] - 'a')];
    }
    
    inline bool isSameAnagrams(vector<int> &anagram_p, vector<int> &anagram_s){
        for(int i = 0; i < anagram_p.size(); ++ i){
            if(anagram_p[i] != anagram_s[i])
                return false;
        }
        return true;
    }
    
    inline void updateAnagramOfStringWithGivenRange(vector<int> &anagram_str, string &s, int l_bnd, int r_bnd) {
        -- anagram_str[(s[l_bnd] - 'a')];
        if(r_bnd < s.size())
            ++ anagram_str[(s[r_bnd] - 'a')];
    }
};
