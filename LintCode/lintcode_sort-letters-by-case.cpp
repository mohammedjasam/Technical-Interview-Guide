/*
*
* Tag: Brute Force
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    /** 
     * @param chars: The letters array you should sort.
     */
    void sortLetters(string &letters) {
        // write your code here
        int lwcnt = 0, upcnt = 0;
        for(int i = 0; i < letters.size(); ++ i){
            if(letters[i] >= 'A' && letters[i] <= 'Z')
                ++ upcnt;
            else
                ++ lwcnt;
        }
        if(!lwcnt || !upcnt)
            return ;
        int lwpt = 0, uppt = letters.size() - 1;
        for(; lwpt < lwcnt; ++ lwpt){
            if(letters[lwpt] >= 'A' && letters[lwpt] <= 'Z'){
                while(letters[uppt] >= 'A' && letters[uppt] <= 'Z') --uppt;
                swap(letters[lwpt], letters[uppt]);
            }
        }
    }
};

