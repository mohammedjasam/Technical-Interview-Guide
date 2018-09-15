/*
*
* Tag: Brute Force
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        if(words.size() == 0)
            return ans;
        string tmp;
        int cur = 0, nxt = 0;
        for(int i = 0; i < words.size(); ++ i){
            tmp = tolower(words[i]);
            cur = 0;
            for(int j = 0; j < tmp.size(); ++ j){
                nxt = getKeyboardLine(tmp[j]);
                if(cur == 0)
                    cur = nxt;
                if(cur != nxt){
                    cur = -1;
                    break;
                }
            }
            if(cur != -1)
                ans.push_back(words[i]);
        }
        return ans;
    }
private:
    inline string tolower(string val){
        string res = val;
        for(int i = 0; i < val.size(); ++ i){
            if(val[i] >= 'A' && val[i] <= 'Z')
                res[i] = (char)(val[i] - 'A' + 'a');
        }
        return res;
    }
    
    inline int getKeyboardLine(char key){
        if(key == 'z' || key == 'x' || key == 'c' || key == 'v' || key == 'b' || key == 'n' || key == 'm')
            return 1;
        else if(key == 'a' || key == 's' || key == 'd' || key == 'f' || key == 'g' || key == 'h' || key == 'j'
            || key == 'k' || key == 'l')
            return 2;
        else
            return 3;
    }
};
