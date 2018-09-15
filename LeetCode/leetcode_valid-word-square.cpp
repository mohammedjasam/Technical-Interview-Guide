/*
*
* Tag:
* Time: O(n^2)
* Space: O(1)
*/
class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        if(words.size() == 0)
            return false;
        int n = words.size(), len_row = 0, len_col = 0;
        for(int i = 0; i < n; ++ i){
            len_row = words[i].size();
            len_col = 0;
            for(int j = 0; i < words[j].size() && j < n; ++ j){
                if(words[i][j] != words[j][i])
                    return false;
                ++ len_col;
            }
            if(len_row != len_col){
                return false;
            }
        }
        return true;
    }
};
