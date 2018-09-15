/*
*
* Tag: Greedy
* Time: O(nlgn)
* Space: O(lgn)
*/
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(g.size() == 0 || s.size() == 0)
            return 0;
        int ans = 0, gid = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        for(int i = 0; i < s.size() && gid < g.size(); ++ i){
            if(s[i] >= g[gid]){
                ++ ans, ++ gid;
            }
        }
        return ans;
    }
};
