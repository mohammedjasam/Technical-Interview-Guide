/*
*
* Tag: Binary Search
* Time: O(lgn)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0. 
     */
    int binarySearch(vector<int> &array, int target) {
        // write your code here
        if(array.size() == 0)
            return -1;
        int l = 0, r = array.size() - 1;
        while(l <= r){
            int mid = (l + r)>>1;
            if(array[mid] == target){
                while(mid >= 0 && array[mid] == target){
                    mid --;
                }
                if(array[mid] == target)
                    return mid;
                else
                    return mid + 1;
            }
            if(array[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }
};
