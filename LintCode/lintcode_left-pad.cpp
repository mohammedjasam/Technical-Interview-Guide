/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(n)
*/
class StringUtils {
public:
    /**
     * @param originalStr the string we want to append to
     * @param size the target length of the string
     * @param padChar the character to pad to the left side of the string
     * @return a string
     */
    static string leftPad(string& originalStr, int size, char padChar=' ') {
        // Write your code here
        int n = originalStr.size();
        if(!size || n >= size)
            return originalStr;
        string ans(size, 0);
        int i = 0, m = size - n, j = 0;
        for(; i < m; ++ i)
            ans[i] = padChar;
        for(; i < size; ++ i, ++ j)
            ans[i] = originalStr[j];
        return ans;
    }
};
