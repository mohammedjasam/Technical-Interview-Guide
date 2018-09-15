/*
*
* Tag: Hash
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    string minWindow(string s, string t) {
        if(!s.size() || s.size() < t.size()){
            return "";
        }
        
        vector<int> curcnt(260), tcnt(260);
        for(int i = 0; i < t.size(); ++ i){
            ++ tcnt[t[i]];
        }
        
        int l = 0, r = 0, len = INT_MAX, num = 0, sta;
        for(int i = 0; i < s.size(); ++ i){
            if(tcnt[s[i]] > 0){
                ++ curcnt[s[i]];
                if(curcnt[s[i]] <= tcnt[s[i]])
                    ++ num;
            }
            
            if(num == t.size()){
                r = i;
                while(curcnt[s[l]] > tcnt[s[l]] || tcnt[s[l]] == 0){
                    -- curcnt[s[l]];
                    ++ l;
                }
                if(len > r - l + 1){
                    len = r - l + 1;
                    sta = l;
                }
            }
        }
        
        return len == INT_MAX ? "" : s.substr(sta, len);
    }
};
