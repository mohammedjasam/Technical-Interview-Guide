/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    bool detectCapitalUse(string word) {
        int capital_cnt = 0;
        bool isFirstCapital = false;
        for(int i = 0; i < word.size(); ++ i){
            if(word[i] >= 'A' && word[i] <= 'Z'){
                ++ capital_cnt;
                if(i == 0)
                    isFirstCapital = true;
            }
        }
        return capital_cnt == 0 || capital_cnt == word.size() || (capital_cnt == 1 && isFirstCapital);
    }
};
