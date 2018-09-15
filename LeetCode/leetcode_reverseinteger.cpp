/*
* Algorithm: Brute force
* Time complexity: O(len(x))
* Memory complexity: O(1)
*/
class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ans = 0;
        if(x==0){
            return ans;
        }
        bool flag = false,positive = true;
        if(x < 0){
            positive = false;
            x *= -1;
        }
        while(x)
        {
            int tmpx = x%10;
            x /= 10;
            ans = ans*10 + tmpx;
        }
        if(ans < 0) return -1;
        if(!positive) ans*=-1;
        return ans;
    }
};
