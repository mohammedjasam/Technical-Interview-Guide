/*
*
* Tag: Brute Force
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        if(!A.size())
            return 0;
        vector<int> presum(A.size()+1), susum(A.size() + 1);
        int n = A.size();
        long long ans = INT_MIN, sufsum = 0, prefsum = 0;
        presum[0] = A[0];
        for(int i = 1; i < n; ++ i){
            presum[i] = presum[i - 1] + A[i];
            prefsum += i*A[i];
        }
        for(int i = n - 1; i >= 0; -- i)
            susum[i] = susum[i + 1] + A[i];
        ans = max(ans, prefsum + sufsum);
        for(int i = n - 1; i >= 0; -- i){
            sufsum += susum[i + 1];
            prefsum = prefsum - (n - 1)*A[i] + presum[i - 1];
            ans = max(ans, prefsum + sufsum);
        }
        return (int)ans;
    }
};
