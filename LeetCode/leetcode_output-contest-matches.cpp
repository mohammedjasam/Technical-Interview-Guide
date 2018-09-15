/*
*
* Tag: Implementation
* Time: O(nlgn)
* Space: O(n)
*/
class Solution {
public:
    string findContestMatch(int n) {
        vector<string> game_match( n + 1 );
        int tot = 0;
        for(int i = 1; i <= n; ++ i )
            game_match[tot ++] = to_string(i);
        while(tot > 1){
            for(int i = 0; i < tot/2; ++ i)
                game_match[i] = "("+game_match[i]+","+game_match[tot - i - 1]+")";
            tot >>= 1;
        }
        return game_match[0];
    }
};
