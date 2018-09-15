/*
*
* Tag: Brute Force
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        // write your code here
        vector<long long> ans;
        int n = nums.size();
        if(n <= 1)
            return ans;
        ans.resize(n);
        vector<long long> res(n + 1);
        res[n] = 1;
        for(int i = n - 1; i >= 1; -- i){
            res[i] = res[i + 1]*nums[i];
        }
        long long mul = 1;
        for(int i = 0; i < n; ++ i){
            ans[i] = mul*res[i + 1];
            mul*=nums[i];
        }
        return ans;
    }
};
