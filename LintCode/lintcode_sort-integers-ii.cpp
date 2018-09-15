class Solution {
public:
    /**
     * @param A an integer array
     * @return void
     */
    void sortIntegers2(vector<int>& A) {
        // Write your code here
        if(!A.size())
            return ;
        sort(A.begin(),A.end());
        return ;
    }
};
