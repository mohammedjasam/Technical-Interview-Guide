/*
*
* Tag: DP
* Time: O(n^2)
* Space: O(n)
*/
public class Solution {
    /**
     * @param s: A string s
     * @param dict: A dictionary of words dict
     */
    public boolean wordSegmentation(String s, Set<String> dict) {
        if (s.length()==0) return true;
        
        char[] chars = new char[256];
        for (String word : dict)
            for (int i=0;i<word.length();i++)
                chars[word.charAt(i)]++;

        for (int i = 0;i<s.length();i++)
            if (chars[s.charAt(i)]==0) return false;

        boolean[] d = new boolean[s.length()+1];
        Arrays.fill(d,false);
        d[0] = true;
        for (int i=1;i<=s.length();i++){
        StringBuilder builder = new StringBuilder();
            for (int j=i-1;j>=0;j--){
                builder.insert(0,s.charAt(j));
                String cur = builder.toString();
                if (d[j] && dict.contains(cur)){
                    d[i]=true;
                    break;
                }
            }
        }

        return d[s.length()];

    }
}
