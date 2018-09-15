/*
*
* Tag: DFS
* Time: O(hn)
* Space: O(h)
*/
class Solution {
private:
    const int MAX_STEP = 6;
public:
    int findMinStep(string board, string hand) {
        sort(hand.begin(), hand.end());
        int res = dfs(board, hand);
        return res > hand.size() ? -1 : res;
    }
private:
    int dfs(string b, string h){
        if(b.empty())
            return 0;
        if(h.empty())
            return MAX_STEP;
        int res = MAX_STEP,  j = 0, n = 0, k = 0;
        string nxtb = "", nxth = "";
        for(int i = 0; i < h.size(); ++ i){
            n = b.size(), j = 0;
            while(j < n){
                k = b.find(h[i], j);
                if(k == string::npos)
                    break;
                if(k < n - 1 && b[k] == b[k + 1]){
                    nxtb = shrink(b.substr(0,k) + b.substr(k + 2));
                    if(nxtb.empty())
                        return 1;
                    nxth = h;
                    nxth.erase(i, 1);
                    res = min(res, dfs(nxtb, nxth) + 1);
                    ++ k;
                }else if(i > 0 && h[i] == h[i - 1]){
                    nxtb = shrink(b.substr(0,k) + b.substr(k + 1));
                    if(nxtb.empty())
                        return 2;
                    nxth = h;
                    nxth.erase(i, 1);
                    nxth.erase(i - 1, 1);
                    res = min(res, dfs(nxtb, nxth) + 2);
                    ++ k;
                }
                j = k + 1;
            }
        }
        return res;
    }
    
    string shrink(string s){
        int start = 0;
        bool done = false;
        while(s.size() > 0){
            start = 0;
            done = true;
            for(int i = 0; i <= s.size(); ++ i){
                if(i == s.size() || s[i] != s[start]){
                    if(i - start >= 3){
                        s = s.substr(0, start) + s.substr(i);
                        done = false;
                        break;
                    }
                    start = i;
                }
            }
            if(done)
                break;
        }
        return s;
    }
    
};
