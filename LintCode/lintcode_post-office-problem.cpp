/*
*
* Tag: DP
* Time: O(n^2)
* Space: O(n^2)
*/
class Solution {
public:
    /**
     * @param A an integer array
     * @param k an integer
     * @return an integer
     */
    int postOffice(vector<int>& A, int k) {
        const int n = A.size();
        if (A.empty() || k >= n) {
            return 0;
        }

        sort(A.begin(), A.end());

        vector<vector<int>> cost(A.size() + 1, vector<int>(A.size() + 1, 0));
        computeMinCost(A, cost);
        
        vector<vector<int>> sum(2, vector<int>(A.size() + 1, INT_MAX));
        sum[0][0] = 0;
        for(int i = 1; i <= k; ++ i){
            for(int j = 0; j <= n; ++ j){
                for(int l = 1; l <= j; ++ l){
                    if(sum[(i - 1)%2][j - l] != INT_MAX){
                        sum[i%2][j] = min(sum[i%2][j], sum[(i - 1)%2][j - l] + cost[j - l + 1][j]);
                    }
                }
            }
        }

        return sum[k%2][n];
    }
    
    void computeMinCost(vector<int>& A, vector<vector<int>> &cost){
        int n = A.size();
        for(int i = 0; i < n; ++ i){
            for(int j = i; j < n; ++ j){
                int mid = (i + j)/2;
                for(int k = i; k <= mid; ++ k){
                    cost[i + 1][j + 1] += A[mid] - A[k];
                }
                for(int k = mid + 1; k <= j; ++ k){
                    cost[i + 1][j + 1] += A[k] - A[mid];
                }
            }
        }
    }
    
};
