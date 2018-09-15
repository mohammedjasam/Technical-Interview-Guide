/*
* Algorithm: DP
* Time complexity: O(n)
* Memory complexity: O(1)
*/
class Solution {
public:
    bool canJump(int A[], int n) {
        int reach = 1;
        for(int i = 0; reach < n && i < reach; i ++){
            reach = max(reach, A[i] + i + 1);
        }
        return reach >= n;
    }
};
