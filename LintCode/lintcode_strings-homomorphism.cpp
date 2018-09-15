/*
*
* Tag: Data Structure (Hash Table)
* Time: O(n)
* Space: O(n)
*/
class Solution {
private:
    const int NUM_OF_KEYS = 300;
public:
    /*
     * @param s: a string
     * @param t: a string
     * @return: true if the characters in s can be replaced to get t or false
     */
    bool isIsomorphic(string s, string t) {
        int dictOfS[NUM_OF_KEYS] = {0}, dictOfT[NUM_OF_KEYS] = {0};
        for(int i = 0; i < s.size(); ++ i){
            int sVal = convertCharToIntVal(t[i]), tVal = convertCharToIntVal(s[i]);
            if(dictOfS[sVal] == 0 && dictOfT[tVal] == 0){
                dictOfS[sVal] = tVal;
                dictOfT[tVal] = sVal;
            }else if(dictOfS[sVal] != tVal || dictOfT[tVal] != sVal)
                return false;
        }
        return true;
    }
private:
    int convertCharToIntVal(char val){
        return ((int)val)+1;
    }
};
