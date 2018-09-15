/*
*
* Tag: Sort or Hash
* Time: O(nlgn) or O(n)
* Space: O(lgn) or O(n)
*/
class Solution {
public:
    /**
     * @param A a string
     * @param B a string
     * @return a boolean
     */
    bool stringPermutation(string& A, string& B) {
        // Write your code here
        if(A == B)
            return true;
        if(A.size() != B.size())
            return false;
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        for(int i = 0; i < A.size(); ++ i){
            if(A[i] != B[i])
                return false;
        }
        return true;
    }
};
