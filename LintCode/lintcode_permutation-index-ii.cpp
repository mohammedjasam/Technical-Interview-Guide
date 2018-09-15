/*
*
* Tag: Hash Map and Math
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     * The index of vector A is the Full Permutation when the first number
     * replace to number which behind it and smaller than it
     * and then iterator to next elements until to the end.
     * and repeat numbers Full Permutation = n!/(repeat numbers!)
     * just map to ps[n]/tmp in the code
     */
    long long permutationIndexII(vector<int>& A) {
        // Write your code here
        int n = A.size();
        if(!n) return 0;
        long long *ps = new long long [n];// records Factorial of n
        ps[0] = 1;
        for(int i=1;i<n;i++){
            ps[i] = ps[i-1]*(i+1);
        }
        long long res = 1;
        int j,start,k;
        unordered_map<int,int> cnts;//records counts of each number behind i
        cnts[A[n-1]] = 1;// from n-1 point
        long long tmp = 1;//current value results to ps[n-2-i]/tmp (tmp means the repeat numbers' Factorial which behind i like Permutation(1122) = 4!/(2!*2!)  or Permutation(111122)= 6!/(4!*2!) just map to ps[n]/tmp)
        for(int i=n-2;i>=0;i--){
            start = A[i];
            cnts[A[i]]++;
            for(j = i + 1 ; j < n ; j++){
                if(A[i] <= A[j]) break;//no more elements smaller than A[i]
                if(start == A[j]) continue;//element has been visited
                else {//new element which smaller than A[i] and haven't been visited
                    start = A[j];
                    res += ps[n-i-2]/(tmp * cnts[A[i]] / cnts[A[j]]);
                }
            }
            tmp *= cnts[A[i]];
            j--;
            //sort elements behind i
            if(i != j){
                start = A[i];
                for(k=i;k<j;k++){
                    A[k] = A[k+1];
                }
                A[j] = start;
            }
        }
        return res;
    }
};
