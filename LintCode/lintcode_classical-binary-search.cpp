/*
*
* Tag: Binary Search
* Time: O(lgn)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param A an integer array sorted in ascending order
     * @param target an integer
     * @return an integer
     */
    int findPosition(vector<int>& A, int target) {
        // Write your code here
        if(A.size() == 0)
            return -1;
        int l = 0, r = A.size(), mid = 0;
        while(l <= r){
            mid = (l + r)>>1;
            if(A[mid] == target)
                return mid;
            else if(A[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }
};
