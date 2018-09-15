/*
*
* Tag: Brute Force + Sort
* Time: O(n^3)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param numbers: Give an array numbersbers of n integer
     * @param target: you need to find four elements that's sum of target
     * @return: Find all unique quadruplets in the array which gives the sum of zero.
     */
    vector<vector<int> > fourSum(vector<int> num, int target) {
        // write your code here
        vector<vector<int>> ans;
        if(num.size() < 4) return ans;
        sort(num.begin(),num.end());
        
        auto last = num.end();
        for(auto a = num.begin(); a < prev(last,3); a ++){
            if(a!=num.begin()){
                while(*a == *(a - 1) && a < prev(last,3)) a ++;
                if(a >= prev(last,3)) break;
            }
            for(auto b = next(a); b < prev(last,2); b ++){
                if(b!=next(a)){
                    while(*b == *(b - 1) && b < prev(last,2)) b ++;
                    if(b >= prev(last,2)) break;
                }
                auto c = next(b);
                auto d = prev(last);
                
                while(c < d){
                    if(*a + *b + *c + *d< target){
                        c ++;
                    }else if(*a + *b + *c + *d> target){
                        d --;
                    }else{
                        ans.push_back({*a,*b,*c,*d});
                        c ++;
                        while(*c == *(c - 1)) c ++;
                        d --;
                        while(*d == *(d + 1)) d --;
                    }
                }
            }
        }
        return ans;
    }
};
