/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    string fractionAddition(string expression) {
        string ans = "";
        int cur_num = 0, cur_den = 1, n = expression.size();
        for(int i = 0; i < n; ++ i){
            int tmp_num = getNum(i, expression), tmp_den = getDen(i, expression);
            calc(cur_num, cur_den, tmp_num, tmp_den);
        }
        ans = to_string(cur_num)+"/"+to_string(cur_den);
        return ans;
    }
private:
    inline int getNum(int &sta, string &expression){
        int res = 0;
        bool isneg = expression[sta] == '-';
        if(expression[sta] == '-' || expression[sta] == '+')
            ++ sta;
        while(expression[sta] != '/') {
            res = res*10 + (expression[sta] - '0');
            ++ sta;
        }
        ++ sta;
        return isneg?-res:res;
    }
    
    inline int getDen(int &sta, string &expression){
        int res = 0;
        while(expression[sta] >= '0' && expression[sta] <= '9' && sta < expression.size()) {
            res = res*10 + (expression[sta] - '0');
            ++ sta;
        }
        -- sta;
        return res;
    }
    
    inline void calc(int &cur_num, int &cur_den, int tmp_num, int tmp_den){
        int gcd_den = gcd(cur_den, tmp_den);
        int nxt_den = cur_den*tmp_den/gcd_den;
        cur_num = nxt_den/cur_den*cur_num;
        tmp_num = nxt_den/tmp_den*tmp_num;
        cur_num += tmp_num;
        cur_den = nxt_den;
        tmp_num = cur_num >= 0? cur_num : -cur_num;
        int gcd_num_den = gcd(tmp_num, cur_den);
        cur_num /= gcd_num_den;
        cur_den /= gcd_num_den;
    }
    
    inline int gcd(int a, int b){
        return b == 0?a:gcd(b, a%b);
    }
};

class Solution {
public:
    string fractionAddition(string expression) {
        istringstream in(expression);
        int A = 0, B = 1, a, b;
        char _;
        while (in >> a >> _ >> b) {
            A = A * b + a * B;
            B *= b;
            int g = abs(__gcd(A, B));
            A /= g;
            B /= g;
        }
        return to_string(A) + '/' + to_string(B);
    }
};
