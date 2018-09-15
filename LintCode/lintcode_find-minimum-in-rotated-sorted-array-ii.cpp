/*
*
* Tag: Binary Search
* Time: O(lgn)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param num: the rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        // write your code here
        int l = 0, r = num.size() - 1;
        if(num.size() == 1)
            return num[0];
        if(num[0] < num[r])
            return num[0];
        if(num[r] < num[r - 1])
            return num[r];
        while(l <= r){
            int mid = (l + r)>>1;
            if(num[mid] < num[mid - 1])
                return num[mid];
            if(num[l] < num[mid]){
                l = mid;
            }else if(num[l] > num[mid]){
                r = mid;
            }else{
                if(num[l] > num[l + 1])
                    return num[l + 1];
                l ++;
            }
        }
        return num[r];
    }
};
