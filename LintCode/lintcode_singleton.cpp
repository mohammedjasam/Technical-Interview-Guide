/*
*
* Tag: Design
* Time: O(1)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @return: The same instance of this class every time
     */
    static Solution* getInstance() {
        // write your code here
        static Solution* pa = new Solution();
        return pa;
    }
    
    // Noncopyable.
    Solution(const Solution&) = delete;
    Solution& operator=(const Solution&) = delete;
    
private:
    Solution() {}
    ~Solution() {}
};
