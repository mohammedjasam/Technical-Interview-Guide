/*
*
* Tag: Brute Force
* Time: O(n)
* Space: O(k)
*/
class Solution{
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */    
    void sortColors2(vector<int> &colors, int k) {
        // write your code here
        vector<int> cnt(k);
        for(int i = 0; i < colors.size(); ++ i){
            ++ cnt[colors[i] - 1];
        }
        int idx = 0;
        for(int i = 0; i < k; ++ i){
            while(cnt[i] --)
                colors[idx ++] = i + 1;
        }
    }
};
