/*
*
* Tag: Math
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int ans = 0;
        if(A.size() < 3)
            return ans;
        int start_idx = -1, end_idx = 0, n = A.size();
        for(int i = 2; i < n; ++ i){
            if(A[i] - A[i - 1] == A[i - 1] - A[i - 2]){
                if(start_idx == -1)
                    start_idx = i - 2;
                end_idx = i;
                if(i == n - 1)
                    ans += countSlices(start_idx, end_idx);
            }else{
                ans += countSlices(start_idx, end_idx);
                start_idx = -1;
            }
        }
        return ans;
    }
private:
    int countSlices(int start_idx, int end_idx){
        if(end_idx - start_idx < 2 || start_idx == -1)
            return 0;
        int n = end_idx - start_idx - 1;
        int sum = (1 + n)*n/2;
        return sum;
    }
};
