/*
*
* Tag: Hash
* Time: O(n)
* Space: O(1)
*/
class Solution {
private:
    const int CHAR_STATE_ARR_LEN = 300;
public:
    /*
     * @param s: a string
     * @return: it's index
     */
    int firstUniqChar(string &s) {
        // write your code here
        if(s == "")
            return -1;
        // 0: char not exist in string; 
        // -1: char duplicated in string;
        // 1: char uniq in string.
        vector<int> char_state(CHAR_STATE_ARR_LEN, 0);
        for(int i = 0; i < s.size(); ++ i){
            int char_int_val = (int)s[i];
            if(hasCharAppearedBefore(char_state, char_int_val))
                char_state[char_int_val] = 1;
            else
                char_state[char_int_val] = -1;
        }
        int ans_idx = -1;
        for(int i = 0; i < s.size(); ++ i){
            int char_int_val = (int)s[i];
            if(isCharUniq(char_state, char_int_val)){
                ans_idx = i;
                break;
            }
        }
        return ans_idx;
    }
private:
    bool hasCharAppearedBefore(vector<int> &char_state, int char_int_val){
        return char_state[char_int_val] == 0;
    }
    
    bool isCharUniq(vector<int> &char_state, int char_int_val){
        return char_state[char_int_val] == 1;
    }
};
