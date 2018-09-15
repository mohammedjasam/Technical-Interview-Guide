/*
*
* Tag: Binary Search
* Time: O(lgn)
* Space: O(1)
*/
class Solution {
    /** 
     * param A : an integer ratated sorted array
     * param target :  an integer to be searched
     * return : an integer
     */
public:
    int search(vector<int> &A, int target) {
        // write your code here
        if(A.size() == 0)
            return -1;
        int l = 0, r = A.size() - 1;
        if(A[l] == target)
            return l;
        if(A[r] == target)
            return r;
        while(l <= r){
            int mid = (l + r)>>1;
            if(A[mid] == target)
                return mid;
            if(A[l] <= A[mid]){
                if(A[mid] > target && target >= A[l])
                    r = mid;
                else
                    l = mid + 1;
            }else{
                if(target > A[mid] && target <= A[r])
                    l = mid + 1;
                else
                    r = mid;
            }
        }
        return -1;
    }
};
