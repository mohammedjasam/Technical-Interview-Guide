/*
*
* Tag: Math
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: Cosine similarity.
     */
    double cosineSimilarity(vector<int> A, vector<int> B) {
        // write your code here
        long long div = 0, a = 0, b = 0;
        if(!A.size() || !B.size() || A.size() != B.size())
            return 2.0000;
        int n = A.size();
        for(int i = 0; i < n; ++ i){
            div += A[i]*B[i];
            a += A[i]*A[i];
            b += B[i]*B[i];
        }
        if(!a || !b)
            return 2.0000;
        return (double)div/((double)sqrt(a*b));
    }
};
