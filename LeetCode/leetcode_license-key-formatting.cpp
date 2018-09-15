/*
*
* Tag: String
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        int len = 0, curGLen = 0, glen = 0, idx = 0;
        char v = 0;
        for(int i = 0; i < S.size(); ++ i){
            if(S[i] != '-')
                ++ len;
        }
        curGLen = len%K == 0?K:len%K;
        string ans(len + (len%K == 0?len/K:len/K+1), 0);
        for(int i = 0; i < S.size(); ++ i){
            if(S[i] == '-')
                continue;
            if(glen >= curGLen){
                v = '-';
                glen = 0, curGLen = K;
                -- i;
            }else{
                if(S[i] >= 'a' && S[i] <= 'z')
                    v = 'A' + (S[i] - 'a');
                else
                    v = S[i];
                ++ glen;
            }
            ans[idx ++] = v;
        }
        return ans;
    }
};
