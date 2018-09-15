/*
*
* Tag: Math
* Time: O(n^0.25)
* Space: O(1)
*/
class Solution {
private:
    const int INVALID_SQUARE_ROOT = -1;
public:
    /*
     * @param : the given number
     * @return:  return true if it has exactly three distinct factors, otherwise false
     */
    bool isThreeDisctFactors(long long n) {
        if(n <= 3)
            return false;
        int squreRoot = getSqureRoot(n);
        if(squreRoot == INVALID_SQUARE_ROOT)
            return false;
        return isPrime(squreRoot);
    }

private:
    int getSqureRoot(long long n){
        long long squreRoot = sqrt(n);
        return squreRoot*squreRoot == n? squreRoot : INVALID_SQUARE_ROOT;
    }
    
    bool isPrime(int n){
        for(int i = 2; i*i <= n; ++ i){
            if(n%i == 0)
                return false;
        }
        return true;
    }
};
