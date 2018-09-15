/*
*
* Tag: Sort + Greedy
* Time: O(nlgn)
* Space: O(n)
*/
class Solution {
public:
    struct numberComparator{
        bool operator() (int a, int b){
            string numA = to_string(a), numB = to_string(b);
            return numB + numA < numA + numB;
        }
    }cmp;

    string largestNumber(vector<int> &num) {
        string ans = "";
        int n = num.size();
        if(n == 0) {
            return ans;
        }
        
        sort(num.begin(), num.end(), cmp);
        int cnt_zero = 0;
        for(int i = 0; i < n; ++ i){
            if(num[i] == 0){
                ++ cnt_zero;
            }
            
            ans += to_string(num[i]);
        }
        
        return cnt_zero == n ? "0" : ans;
    }

};
