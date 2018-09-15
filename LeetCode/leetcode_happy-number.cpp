/*
*
* Tag: Math
* Time: ?
* Space: ?
*/
class Solution {
public:
    bool isHappy(int n) {
        if(n == 0){
            return false;
        }
        
        unordered_set<int> st;
        st.insert(n);
        while(n != 1){
            n = getNextNum(n);
            if(st.count(n) != 0){
                return false;
            }
            
            st.insert(n);
        }
        
        return true;
    }
    
private:    
    int getNextNum(int n){
        int res = 0;
        while(n){
            int val = n%10;
            res += val*val;
            n /= 10;
        }
        
        return res;
    } 
};
