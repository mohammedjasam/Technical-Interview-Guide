/*
*
* Tag: DFS
* Time: O(n^k)
* Space: O(k)
*/
class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return a list of lists of integer 
     */
    vector<vector<int> > kSumII(vector<int> A, int k, int target) {
        // write your code here
        vector<vector<int> > ans;
        if(!A.size() || !k)
            return ans;
        sort(A.begin(), A.end());
        int n = A.size();
        for(int i = 0; i < n; ++ i){
            vector<int> tmp(k);
            int sum = A[i];
            if(sum > target)
                break;
            tmp[0] = A[i];
            dfs(A, k, tmp, ans, sum, 1, target, i);
        }
        return ans;
    }
    
    void dfs(vector<int> A, int k, vector<int> tmp, vector<vector<int>> &ans, int sum, int depth, int target, int id){
        if(depth >= k){
            if(sum == target)
                ans.push_back(tmp);
            return ;
        }
        int n = A.size();
        for(int i = id + 1; i < n; ++ i){
            sum += A[i];
            if(sum > target)
                break;
            tmp[depth] = A[i];
            dfs(A, k, tmp, ans, sum, depth + 1, target, i);
            sum -= A[i];
        }
    }
};

