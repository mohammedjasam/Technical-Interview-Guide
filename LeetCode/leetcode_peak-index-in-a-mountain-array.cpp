/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int ans = 1;
        
        for(int i = 1; i < A.size(); ++ i){
            if(A[i] > A[i - 1]){
                ans = i;
            } else {
                break;
            }
        }
        
        return ans;
    }
};
