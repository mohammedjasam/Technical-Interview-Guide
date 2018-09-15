/*
*
* Tag: Hash
* Time: O(n)
* Space: O(k)
*/
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int ans = 0;
        if(!s.size() || !k)
            return ans;
        int cntk = 0, j = 0, n = s.size();
        for(int i = 0; i < n; ++ i){
            if(dict[s[i]] == 0){
                ++ cntk;
            }
            ++ dict[s[i]];
            while(cntk > k && j <= i){
                -- dict[s[j]];
                if(dict[s[j]] == 0)
                    -- cntk;
                ++ j;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
private:
unordered_map<char,int> dict;
};

/*
* A more efficient solution
*/
class Solution {
private:
    int dict[300];
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int ans = 0;
        if(!s.size() || !k){
            return ans;
        }
        
        int cntk = 0, j = 0, n = s.size();
        for(int i = 0; i < n; ++ i){
            if(dict[(int)s[i]] == 0){
                ++ cntk;
            }
            
            ++ dict[(int)s[i]];
            while(cntk > k && j <= i){
                -- dict[(int)s[j]];
                if(dict[(int)s[j]] == 0){
                    -- cntk;
                }
                
                ++ j;
            }
            
            ans = max(ans, i - j + 1);
        }
        
        return ans;
    }
};
