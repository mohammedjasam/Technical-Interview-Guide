/*
*
* Tag: Brute Force
* Time: O(n^2)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: a integer
     */
    int trapRainWater(vector<int> &A) {
        // write your code here
        int n = A.size();
        if(n == 0)
            return 0;
        int ans = 0;
        for(int i = 0; i < n; ++ i){
            if(!A[i])
                continue;
            int sum = 0;
            for(int j = i + 1; j < n; ++ j){
                if(A[i] <= A[j]){
                    ans += sum;
                    i = j - 1;
                    break;
                }else if(j < n - 1){
                    sum += (A[i] - A[j]);
                }else if( j == n - 1){
                    ans += reverse(i, j, A);
                    i = j;
                }
            }
        }
        return ans;
    }
    
    int reverse(int sta, int end, vector<int> &A){
        int sum = 0;
        for(int i = end - 1; i >= sta; -- i){
            if(A[i] >= A[end]){
                end = i;
            }else{
                sum += (A[end] - A[i]);
            }
        }
        return sum;
    }
};
