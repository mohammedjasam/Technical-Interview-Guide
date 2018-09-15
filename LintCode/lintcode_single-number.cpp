/*
*
* Tag: Bit Manipulation
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
	/**
	 * @param A: Array of integers.
	 * return: The single number.
	 */
    int singleNumber(vector<int> &A) {
        // write your code here
        if(A.size() == 0)
            return 0;
    	int ans = A[0], n = A.size();
    	for(int i = 1; i < n; ++ i)
    		ans ^= A[i];
    	return ans;
    }

};
