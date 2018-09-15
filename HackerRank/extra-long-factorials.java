/*
*
* Tag: Math
* Time: O(n)
* Space: O(1)
*/
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner scanf = new Scanner(System.in);
        int n = scanf.nextInt();
        BigInteger ans = new BigInteger("1");
        BigInteger mul = new BigInteger("2");
        for(int i = 2; i <= n; ++ i){
            ans = ans.multiply(mul);
            mul = mul.add(BigInteger.ONE);
        }
        System.out.println(ans.toString());
    }
}
