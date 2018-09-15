/*
*
* Tag: Binary Search
* Time: O(lgn)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param num: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        // write your code here
        if(num.size() == 1)
            return num[0];
        int l = 0, r = num.size() - 1;
        if(num[l] < num[r])
            return num[l];
        if(num[r] < num[r - 1])
            return num[r];
        while(l <= r){
            int mid = (l + r)>>1;
            if(num[mid - 1] > num[mid])
                return num[mid];
            if(num[l] < num[mid])
                l = mid;
            else
                r = mid;
        }
    }
};
