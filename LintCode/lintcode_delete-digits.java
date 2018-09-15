/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(n)
*/
public class Solution {
    /**
     *@param A: A positive integer which has N digits, A is a string.
     *@param k: Remove k digits.
     *@return: A string
     */
    public String DeleteDigits(String A, int k) {
        Stack<Integer> st = new Stack<Integer>();
        int popCount = 0;
        StringBuffer res = new StringBuffer();
        for (int i=0; i<A.length(); i++) {
            int num = (int)(A.charAt(i) - '0');
            if (st.isEmpty()) st.push(num);
            else if (num >= st.peek()) {
                st.push(num);
            }
            else {
                if (popCount < k) {
                    st.pop();
                    i--;
                    popCount++;
                }
                else {
                    st.push(num);
                }
            }
        }
        while (popCount < k) {
            st.pop();
            popCount++;
        }
        while (!st.isEmpty()) {
            res.insert(0, st.pop());
        }
        while (res.length() > 1 && res.charAt(0) == '0') {
            res.deleteCharAt(0);
        }
        return res.toString();
    }
}
