/*
*
* Tag: Brute Force
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    /**
      * @param n: n
      * @param k: the kth permutation
      * @return: return the k-th permutation
      */
    string getPermutation(int n, int k) {
        vector<int> num(n);
        int pc = 1;
        for(int i = 0; i < n; ++ i){
            pc = pc*(i + 1);
            num[i] = i + 1;
        }
        string ans = "";
        k --;
        for(int i = 0; i < n; ++ i){
            pc = pc/(n - i);
            int id = k/pc;
            ans += (num[id] + '0');
            for(int j = id; j < n - i - 1; ++ j)
                num[j] = num[j + 1];
            k = k%pc;
        }
        return ans;
    }
};
