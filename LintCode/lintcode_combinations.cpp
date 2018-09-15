/*
* Tag: DFS
* Time: O(2^n)
* Space: O(n)
*/
class Solution {
public:
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    vector<vector<int> > combine(int n, int k) {
        // write your code here
        vector<vector<int> > ans;
        for(int i = 1; i <= n; ++ i){
            vector<int> tmp_vec(k);
            tmp_vec[0] = i;
            dfs(i,1,n,k,tmp_vec,ans);
        }
        return ans;
    }
    
    void dfs(int sta, int depth, int n,int k, vector<int> tmp_vec, vector<vector<int> > &ans){
        if(depth == k){
            ans.push_back(tmp_vec);
            return ;
        }
        for(int i = sta + 1; i <= n; ++ i){
            tmp_vec[depth] = i;
            dfs(i,depth + 1,n,k,tmp_vec,ans);
        }
    }
};
