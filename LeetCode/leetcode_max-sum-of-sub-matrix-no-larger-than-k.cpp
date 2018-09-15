/*
*
* Tag: Binary Search (using Set data structure)
* Time: O((n^2)*nlgn)
* Space: O(n)
*/
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int ans = 0;
        if(!matrix.size())
            return ans;
        int row = matrix.size(), col = matrix[0].size();
        ans = INT_MIN;
        for(int c = 0; c < col; ++ c){
            vector<int> sum(row, 0);
            for(int l = c; l < col; ++ l){
                for(int r = 0; r < row; ++ r){
                    sum[r] += matrix[r][l];
                }
                
                set<int> st;
                st.insert(0);
                int cursum = 0;
                for(int i = 0; i < sum.size(); ++ i){
                    cursum += sum[i];
                    set<int>::iterator it = st.lower_bound(cursum - k);
                    if(it != st.end())
                        ans = max(ans, cursum - *it);
                    st.insert(cursum);
                }
            }
        }
        return ans;
    }
};
