/*
* Algorithm: DP
* Time complexity: O(n)
* Memory complexity: O(1)
*/
class Solution {
public:
    int jump(int A[], int n) {
        int step = 0;
        int left = 0, right = 0;
        if(n == 1) return 0;
        
        while(left<=right){
            step ++;
            const int old_right = right;
            for(int i = left; i <= old_right; i ++){
                int new_right = i + A[i];
                if(new_right >= n - 1) return step;
                
                if(new_right > right) right = new_right;
            }
            left = old_right + 1;
        }
        return 0;
    }
};
