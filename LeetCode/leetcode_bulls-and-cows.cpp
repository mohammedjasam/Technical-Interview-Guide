/*
*
* Tag: Hash
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    string getHint(string secret, string guess) {
        int cntb = 0, cntc = 0;

        vector<int> vis(10, 0);
        for(int i = 0; i < secret.size(); ++ i){
            ++ vis[secret[i] - '0'];
        }
        
        for(int i = 0; i < secret.size(); ++ i){
            if(secret[i] == guess[i]){
                ++ cntb;
                -- vis[guess[i] - '0'];
            }
        }
        for(int i = 0; i < secret.size(); ++ i){
            if(secret[i] != guess[i]){
                if(vis[guess[i] - '0']){
                    ++ cntc;
                    -- vis[guess[i] - '0'];
                }
            }
        }
        
        string ans = to_string(cntb) + "A" + to_string(cntc) + "B";
        return ans;
    }
};
