/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        string ans = "";
        pair<int,int> pa = getComplexityVal(a), pb = getComplexityVal(b), pc;
        pc.first = (pa.first*pb.first - pa.second*pb.second), pc.second = (pa.first*pb.second + pa.second*pb.first);
        ans = to_string(pc.first) + "+" + to_string(pc.second) + "i";
        return ans;
    }
private:
    pair<int,int> getComplexityVal(string val){
        string a, b;
        int idx = 0, n = val.size();
        for(; val[idx] != '+'; ++ idx) ;
        a = val.substr(0, idx), b = val.substr(idx + 1, n - idx - 2);
        return make_pair(stoi(a), stoi(b));
    }
};
