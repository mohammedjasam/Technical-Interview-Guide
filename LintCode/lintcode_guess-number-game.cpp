/*
*
* Tag: Binary Search
* Time: O(lgn)
* Space: O(1)
*/
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    /**
     * @param n an integer
     * @return the number you guess
     */
    int guessNumber(int n) {
        int left = 1, right = n;
        int ans = n;
        while(left <= right) {
            int mid = left + (right - left)/2;
            int guessRes = guess(mid);
            if(guessRes == 0) {
                ans = mid;
                break;
            } else if(guessRes == -1) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
