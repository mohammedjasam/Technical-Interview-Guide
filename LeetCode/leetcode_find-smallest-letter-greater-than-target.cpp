/*
*
* Tag: Binary Search
* Time: O(lgn)
* Space: O(1)
*/
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if(target >= letters.back() || target < letters.front()){
            return letters.front();
        }
        
        int l = 0, r = letters.size() - 1;
        while(l < r){
            int mid = (l + r)>>1;
            if(letters[mid] > target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        
        return letters[l];
    }
};
