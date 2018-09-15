/*
*
* Tag: Bit Manipulation
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
	/**
	 * @param A : An integer array
	 * @return : An integer 
	 */
    int singleNumberII(vector<int> &A) {
        // write your code here
        int ans = 0;
        vector<int> bitcnt(32);
        for(int i = 0; i < A.size(); ++ i){
            int val = A[i], cnt = 0;
            while(val){
                if(val&1)
                    ++ bitcnt[cnt];
                val>>=1;
                ++ cnt;
            }
        }
        for(int i = 0; i < 32; ++ i){
            if(bitcnt[i]%3)
                ans |= (1<<i);
        }
        return ans;
    }
};
