/*
* Algorithm: Brute force
* Time complexity: O(n)
* Memory complexity: O(1)
*/
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int c[m+n+10];
        int ida = 0,idb = 0, idc = 0;
        for(;ida < m && idb < n;){
            if(A[ida]>=B[idb]){
                c[idc++]=B[idb++];
            }else{
                c[idc++]=A[ida++];
            }
        }
        while(ida<m) c[idc++]=A[ida++];
        while(idb<n) c[idc++]=B[idb++];
        for(int i = 0; i < idc; i ++){
            A[i]=c[i];
        }
    }
};
