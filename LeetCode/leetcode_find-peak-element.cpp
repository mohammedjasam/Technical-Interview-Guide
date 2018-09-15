/*
*
* Tag: Binary Search
* Time: O(lgn)
* Space: O(1)
*/
class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int len = num.size();
        if(len == 1 || num[0] > num[1]) {
            return 0;
        }
        
        if(num[len - 1] > num[len - 2]) {
            return len - 1;
        }
        
        int l = 1, r = len - 2;
        while(l <= r){
            int mid = (l + r)>>1;
            if(num[mid] > num[mid - 1] && num[mid] > num[mid + 1]){
                return mid;
            }
            
            if(num[mid] >= num[mid - 1] && num[mid] <= num[mid + 1]){
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        return -1;
    }
};
