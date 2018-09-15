/*
*
* Tag: Brute Force
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    /**
     * @param A: An integer array.
     * @return an integer array
     */
    vector<int> rerange(vector<int> &A) {
        // write your code here
        if(A.size() < 3)
            return A;
        int poscnt = 0, negcnt = 0;
        int n = A.size();
        for(int i = 0; i < n; ++ i){
            if(A[i] > 0)
                ++ poscnt;
            else
                ++ negcnt;
        }
        int bk = n - 1;
        for(int i = 0; i < n; ++ i){
            if(i%2 == 0){
                if(poscnt >= negcnt){
                    if(A[i] < 0){
                        for(bk = n - 1; bk >= 0; -- bk){
                            if(A[bk] > 0 && bk%2){
                                swap(A[i],A[bk]);
                                break;
                            }
                        }
                    }
                }else{
                    if(A[i] > 0){
                        for(bk = n - 1; bk >= 0; -- bk){
                            if(A[bk] < 0 && bk%2){
                                swap(A[i],A[bk]);
                                break;
                            }
                        }
                    }
                }
            }else{
                if(poscnt >= negcnt){
                    if(A[i] > 0){
                        for(bk = n - 1; bk >= 0; -- bk){
                            if(A[bk] < 0 && bk%2 == 0){
                                swap(A[i],A[bk]);
                                break;
                            }
                        }
                    }    
                }else{
                    if(A[i] < 0){
                        for(bk = n - 1; bk > 0; -- bk){
                            if(A[bk] >= 0 && bk%2 == 0){
                                swap(A[i],A[bk]);
                                break;
                            }
                        }
                    }
                }
            }
        }
        return A;
    }
};
