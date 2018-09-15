/*
* Algorithm: Math
* Time complexity: O(1)
* Memory complexity: O(1)
*/
class Solution {
public:
    int climbStairs(int n) {
        const double s = sqrt(5);
        return floor((pow((1 + s)/2, n + 1) + pow((1 - s)/2, n + 1))/s + 0.5);
    }
};

/*
* Algorithm: DP
* Time complexity: O(n)
* Memory complexity: O(1)
*/
class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
        int sum = 0, sumprev1 = 1, sumprev2 = 2;
        for(int i = 3; i <= n; i ++){
            sum = sumprev1 + sumprev2;
            sumprev1 = sumprev2;
            sumprev2 = sum;
        }
        return sum;
    }
};

