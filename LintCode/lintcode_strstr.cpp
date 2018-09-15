/*
*
* Tag: String Matching 
* Solution: KMP algorithm
* Time: O(n)
* Space: O(n)
*
*/
class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        // write your code here
        if(source == NULL || target == NULL)
            return -1;
        int n = strlen(source), m = strlen(target);
        if(!m)
            return 0;
        if(!n)
            return -1;
        vector<int> next(m + 1);
        getNext(next, target);
        return KMP(source, target, next, n, m);
    }
    
    void getNext(vector<int> &next, const char *target){
        int i = 0, j = -1;
        next[0] = -1;
        while(target[i]){
            if(j == -1 || target[i] == target[j]){
                ++ i;
                ++ j;
                next[i] = j;
            }else{
                j = next[j];
            }
        }
    }
    
    int KMP(const char *source, const char *target, vector<int> &next, int n, int m){
        int i = 0, j = 0;
        while(i < n && j < m){
            if(j == -1 || source[i] == target[j]){
                ++ i;
                ++ j;
            }else{
                j = next[j];
            }
        }
        if(j >= m)
            return i - m;
        else
            return -1;
    }
};

