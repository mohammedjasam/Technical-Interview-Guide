/*
*
* Tag: Math + Data Structure
* Time: O(denominator)
* Space: O(denominator)
*/
class Solution {
private:
    unordered_map<long long, int> divRemain;
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long numer = numerator, denomin = denominator;
        string ans = "";
        if((numer < 0 && denomin > 0) || (numer > 0 && denomin < 0))
            ans += '-';
        if(numer < 0)
            numer = -numer;
        if(denomin < 0)
            denomin = -denomin;
        ans += to_string(numer/denomin);
        if(numer%denomin != 0){
            ans += '.';
            ans += getFloatVal(numer,denomin);
        }
        
        return ans;
    }
    
    string getFloatVal(long long numer, long long denomin){
        string res = "", tmpres = "";
        int pos = 0, idx;
        bool is_endless = false;
        while(numer%denomin){
            long long div = numer%denomin;
            if(divRemain.count(div) != 0){
                is_endless = true;
                idx = divRemain[div];
                break;
            }else{
                divRemain[div] = pos;
                ++ pos;
            }
            
            div *= 10;
            long long new_val = div/denomin;
            tmpres += to_string(new_val);
            numer = div%denomin;
        }
        
        if(is_endless){
            int i = 0;
            for(; i < idx; ++ i)
                res += tmpres[i];
            res += '(';
            for(; i < tmpres.size(); ++ i)
                res += tmpres[i];
            res += ')';
        }else{
            res += tmpres;
        }
        
        return res;
    }
    
};
