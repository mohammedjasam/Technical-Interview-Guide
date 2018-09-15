/*
*
* Tag: Design
*/
class Solution {
    private static volatile Solution instance = new Solution();
    /**
     * @return: The same instance of this class every time
     */
    private Solution() {
    }
 
    public static Solution getInstance() {
        // write your code here
        return instance;
    }
};
