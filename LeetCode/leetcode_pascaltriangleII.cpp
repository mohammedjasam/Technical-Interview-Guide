/*
* Algorithm: Brute force
* Time complexity: O(n^2)
* Memory complexity: O(n)
*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans = vector<int>(rowIndex + 1,0);
        ans[0] = 1;
        for(int i = 1; i <= rowIndex; i ++){
            ans[i] = 1;
            for(int j = i - 1; j > 0; j --){
                ans[j] = ans[j] + ans[j - 1];
            }
        }
        return ans;
    }
};
