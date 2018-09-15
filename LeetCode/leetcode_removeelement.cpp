/*
* Algorithm: Brute force
* Time complexity: O(n)
* Memory complexity: O(n)
*/
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int loc_idx = 0;
        int len = n;
        for(int i = 0; i < n; i ++){
            if(elem != A[i]){
                A[loc_idx] = A[i];
                ++ loc_idx;
            }else
                len --;
        }
        return len;
    }
};

