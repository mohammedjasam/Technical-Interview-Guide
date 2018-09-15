/*
*
* Tag: DP
* Time: O(nm)
* Space: O(nm)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <list>
#include <climits>
#include <cstdint>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <assert.h>
using namespace std;

//dp[i][j] = dp[0][0] = true
//           dp[i - 1][j - 1] where p[i] == s[j] || p[i] == '.'
//           dp[i - 2][j]  where p[i] == '*' && p[i - 1] != s[j]
//           dp[i - 2][j] || dp[i - 1][j] || dp[i][j - 1] where p[i] == '*' && (p[i - 1] == '.' || p[i - 1] == s[j])
//           dp[i - 1][j] || dp[i][j - 1] where p[i] == '+' && (p[i - 1] == '.' || p[i - 1] == s[j])
//dp[lenP][lenS]

class PatterMatcher {
public:
    bool isMatch(string &s, string &p){
        if(s == p){
            return true;
        }
        
        int lenOfS = s.size(), lenOfP = p.size();
        vector<vector<bool>> dp(lenOfP + 1, vector<bool>(lenOfS + 1, false));
        dp[0][0] = true;
        for(int i = 1; i <= lenOfP; ++ i){
            dp[i][0] = p[i - 1] == '*' && (i >= 2 && dp[i - 2][0]);
        }
        
        for(int i = 1; i <= lenOfP; ++ i){
            for(int j = 1; j <= lenOfS; ++ j){
                if(p[i - 1] == s[j - 1] || p[i - 1] == '.'){
                    dp[i][j] = dp[i - 1][j - 1];
                } else if(p[i - 1] == '*' || p[i - 1] == '+'){
                    
                    if(p[i - 2] == '.' || p[i - 2] == s[j - 1]) {
                        if(p[i - 1] == '*') {
                            dp[i][j] = dp[i - 1][j] || dp[i][j - 1] || (i >= 2 && dp[i - 2][j]);
                        } else {
                            dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                        }
                        
                    } else {
                        dp[i][j] = p[i - 1] == '*' && (i >= 2 && dp[i - 2][j]);
                    }
                    
                }
            }
        }
        
        return dp[lenOfP][lenOfS];
    }
};

int main() {
    PatterMatcher pm;
    
    string s = "", p = "";
    assert( pm.isMatch(s, p) );
    
    s = "", p = "*";
    assert( !pm.isMatch(s, p) );
    
    s = "", p = ".";
    assert( !pm.isMatch(s, p) );
    
    s = "", p = "+";
    assert( !pm.isMatch(s, p) );
    
    s = "aab", p = "aab";
    assert( pm.isMatch(s, p) );
    
    s = "aab", p = "a*b";
    assert( pm.isMatch(s, p) );
    
    s = "aab", p = "a.b";
    assert( pm.isMatch(s, p) );
    
    s = "aab", p = "a+b";
    assert( pm.isMatch(s, p) );
    
    s = "aab", p = "a.*";
    assert( pm.isMatch(s, p) );
    
    s = "aab", p = "a.+";
    assert( pm.isMatch(s, p) );
    
    s = "aab", p = ".*";
    assert( pm.isMatch(s, p) );
    
    s = "aab", p = ".+";
    assert( pm.isMatch(s, p) );
    
    s = "aab", p = ".*b";
    assert( pm.isMatch(s, p) );
    
    s = "aab", p = ".+b";
    assert( pm.isMatch(s, p) );
    
    s = "aab", p = "a.+b";
    assert( pm.isMatch(s, p) );
    
    s = "aabccdefgh", p = "a.*b.*de+";
    assert( !pm.isMatch(s, p) );
    
    s = "aabccdefgh", p = "a.*b.*de+gh";
    assert( !pm.isMatch(s, p) );
    
    s = "saaaa", p = "s+a*";
    assert( pm.isMatch(s, p) );
    
    s = "saaaab", p = "s+a*";
    assert( !pm.isMatch(s, p) );
    
    s = "saaaab", p = "s+b*";
    assert( !pm.isMatch(s, p) );
    
    s = "saaaaa", p = "s+b*";
    assert( !pm.isMatch(s, p) );
    return 0;
}
