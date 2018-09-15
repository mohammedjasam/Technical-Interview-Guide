/*
*
* Tag: DFS
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    /**
     * @param n: An integer.
     * return : An array storing 1 to the largest number with n digits.
     */
    vector<int> numbersByRecursion(int n) {
        // write your code here
        vector<int> ans;
        if(!n)
            return ans;
        dfs(ans, n, 1, 9);
    }
    
    void dfs(vector<int> &ans, int n, int low, int high){
        if(!n)
            return ;
        for(int i = low; i <= high; ++ i)
            ans.push_back(i);
        low = low*10;
        high = high*10 + 9;
        dfs(ans, n - 1, low, high);
    }
};
