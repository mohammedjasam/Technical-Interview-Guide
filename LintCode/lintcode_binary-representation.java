/*
*
* Tag: Bit Manipulation
* Time: O(n)
* Space: O(1)
*/
public class Solution {
    /**
     *@param n: Given a decimal number that is passed in as a string
     *@return: A string
     */
    public String binaryRepresentation(String n) {
        int intPart = Integer.parseInt(n.substring(0, n.indexOf('.')));
        double decPart = Double.parseDouble(n.substring(n.indexOf('.')));
        String intstr = "";
        String decstr = "";
        
        if (intPart == 0) intstr += '0';
        while (intPart > 0) {
            int c = intPart % 2;
            intstr = c + intstr;
            intPart = intPart / 2;
        }
       
        while (decPart > 0.0) {
            if (decstr.length() > 32) return "ERROR";
            double r = decPart * 2;
            if (r >= 1.0) {
                decstr += '1';
                decPart = r - 1.0;
            }
            else {
                decstr += '0';
                decPart = r;
            }
        }
        return decstr.length() > 0? intstr + "." + decstr : intstr;
    }
}
