/*
*
* Tag: Bineary Search
* Time: O(lgn)
* Space: O(1)
*/
class Solution {
    /** 
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector<int> &A, int target) {
        // write your code here
        int ans = 0;
        if(!A.size())
            return ans;
        if(target <= A[0])
            return ans;
        int n = A.size();
        if(target > A[n - 1])
            return n;
        if(target == A[n - 1])
            return n - 1;
        int l = 0, r = n - 1;
        bool isfind = false;
        while(l <= r){
            int mid = (l + r)>>1;
            if(A[mid] == target){
                ans = mid;
                isfind = true;
                break;
            }else if(A[mid] > target){
                r = mid - 1;
            }else if(A[mid] < target){
                ans = mid + 1;
                l = mid + 1;
            }
        }
        if(!isfind){
            //while(A[ans + 1] < target) ++ ans;
        }
        return ans;
    }
};
