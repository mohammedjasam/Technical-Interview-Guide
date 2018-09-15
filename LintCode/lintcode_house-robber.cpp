/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param A: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> A) {
        // write your code here
        if(!A.size())
            return 0;
        if(A.size() == 1)
            return A[0];
        if(A.size() == 2)
            return (long long)max(A[0], A[1]);
        long long pre = A[0], cur = max(A[0], A[1]), ans = A[0];
        for(int i = 2; i < A.size(); ++ i){
            long long sum = A[i] + pre;
            ans = max(ans, max(sum, cur));
            pre = cur;
            cur = ans;
        }
        return ans;
    }
};
