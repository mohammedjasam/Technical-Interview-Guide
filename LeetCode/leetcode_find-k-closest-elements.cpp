/*
*
* Tag: Binary Search + Two Pointers
* Time: O(nlgn)
* Space: O(n)
*/
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        if(k < 1){
            return ans;
        }
        
        ans.resize(k);
        int startIndex = findStartIndex(arr, x);
        int leftForwardPtr = startIndex, rightForwardPtr = startIndex + 1;
        for(int i = 0; i < k && (leftForwardPtr >= 0 || rightForwardPtr < arr.size()); ++ i) {
            int DifferenceForLeftPtrVal = INT_MAX,  DifferenceForRightPtrVal = INT_MAX;
            if(leftForwardPtr >= 0){
                DifferenceForLeftPtrVal = abs(arr[leftForwardPtr] - x);
            }
            if(rightForwardPtr < arr.size()){
                DifferenceForRightPtrVal = abs(arr[rightForwardPtr] - x);
            }
            
            if(DifferenceForLeftPtrVal <= DifferenceForRightPtrVal){
                ans[i] = arr[leftForwardPtr];
                -- leftForwardPtr;
            } else {
                ans[i] = arr[rightForwardPtr];
                ++ rightForwardPtr;
            }
            
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
    
private:
    int findStartIndex(vector<int>& arr, int x){
        int l = 0, r = arr.size() - 1;
        while(l < r){
            int mid = (l + r)>>1;
            if(arr[mid] < x){
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        
        return arr[l] == x ? l : l - 1;
    }
};
