/*
*
* Tag: Binary Search
* Time: O(lgn)
* Space: O(1)
*/
class Solution {
    /** 
     * param A : an integer ratated sorted array and duplicates are allowed
     * param target :  an integer to be search
     * return : a boolean 
     */
public:
    bool search(vector<int> &A, int target) {
        // write your code here
        if(!A.size())
            return false;
        int l = 0, r = A.size() - 1;
        if(A[l] == target || A[r] == target)
            return true;
        while(l <= r){
            int mid = (l + r)>>1;
            if(A[mid] == target)
                return true;
            if(A[l] < A[mid]){
                if(target == A[l])
                    return true;
                if(target > A[l] && target < A[mid])
                    r = mid - 1;
                else
                    l = mid;
            }else if(A[l] > A[mid]){
                if(target == A[r])
                    return true;
                if(A[r] > target && target > A[mid])
                    l = mid + 1;
                else
                    r = mid;
            }else
                ++ l;
        }
        return false;
    }
};
