/*
*
* Tag: DP
* Time: O(nm)
* Space: O(m)
*/
class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     */
    int backPack(int m, vector<int> A) {
        // write your code here
        vector<bool> bkp(m + 1);
        sort(A.begin(), A.end());
        bkp[0] = 1;
        for(int i = 1; i <= m; ++ i)
            bkp[i] = 0;
        for(int i = 0; i < A.size(); ++ i){
            for(int j = m; j >= A[i]; -- j){
                if(bkp[j - A[i]])
                    bkp[j] = bkp[j - A[i]];
            }
        }
        int ans = 0;
        for(int j = m; j >= 0; -- j){
            if(bkp[j]){
                ans = j;
                break;
            }
        }
        return ans;
    }
};
