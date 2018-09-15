/*
*
* Tag: Brute Force
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true 
     *           else return false
     */
    bool compareStrings(string A, string B) {
        // write your code here
        if(B.size() == 0 || B =="")
            return true;
        vector<int> cnt_a(26), cnt_b(26);
        int id;
        for(int i = 0; i < A.size(); ++ i){
            id = A[i] - 'A';
            cnt_a[id] ++;
        }
        for(int i = 0; i < B.size(); ++ i){
            id = B[i] - 'A';
            cnt_b[id] ++;
        }
        for(int i = 0; i < 26; ++ i){
            if(cnt_a[i] < cnt_b[i])
                return false;
        }
        return true;
    }
};
