/*
*
* Tag: Bit Manipulation + DFS
* Time: O(n)
* Space: O(n)
*/
class Solution {
private:
    const string SYMBOLS = "0110100110010110";
public:
    int kthGrammar(int N, int K) {
        if(N <= 5){
            return (SYMBOLS[(K - 1)%SYMBOLS.size()] - '0');
        }
        
        int halfLenOfSymbols = 1<<(N - 2);
        return K <= halfLenOfSymbols ? kthGrammar(N - 1, K) : (kthGrammar(N - 1, K - halfLenOfSymbols)^1);
    }
};
