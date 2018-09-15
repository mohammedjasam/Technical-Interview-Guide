/*
*
* Tag: Brute Force
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        if(word == abbr)
            return true;
        int widx = 0, abridx = 0;
        int num = 0;
        while(widx < word.size() && abridx < abbr.size()){
            num = 0;
            if(word[widx] == abbr[abridx]){
                ++ widx;
                ++ abridx;
            }else{
                if(abbr[abridx] <= '0' || abbr[abridx] > '9')
                    return false;
                while((abbr[abridx] >= '0' && abbr[abridx] <= '9') && abridx < abbr.size()){
                    num = num*10 + (abbr[abridx] - '0');
                    ++ abridx;
                }
                if(num > (word.size() - widx))
                    return false;
                widx += num;
            }
        }
        return widx >= word.size() && abridx >= abbr.size();
    }
};
