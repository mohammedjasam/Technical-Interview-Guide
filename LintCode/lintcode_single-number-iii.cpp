/*
*
* Tag: Data Structure (Hash)
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    /**
     * @param A : An integer array
     * @return : Two integers
     */
    vector<int> singleNumberIII(vector<int> &A) {
        // write your code here
        vector<int> ans;
        if(A.size() < 2)
            return ans;
        unordered_set<int> st;
        for(int i = 0; i < A.size(); ++ i){
            if(st.find(A[i]) == st.end())
                st.insert(A[i]);
            else
                st.erase(A[i]);
        }
        for(unordered_set<int>::iterator it = st.begin(); it != st.end(); ++ it)
            ans.push_back(*it);
        return ans;
    }
};
