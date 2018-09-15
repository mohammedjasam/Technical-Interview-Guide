/*
*
* Tag: String
* Time: O(n^1.5)
* Space: O(n^1.5)
*/
class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        if(str.size() <= 1)
            return false;
        vector<string> subSet(str.size());
        int subCnt = 0;
        genSubPattern(str, subCnt, subSet);
        for(int i = 0; i < subCnt; ++ i){
            if(isRepeat(subSet[i], str))
                return true;
        }
        return false;
    }
private:
    void genSubPattern(string &str, int &subCnt, vector<string> &subSet){
        int n = str.size();
        for(int i = 1; i*i <= n; ++ i){
            if(n%i == 0){
                subSet[subCnt ++] = str.substr(0, i);
                if(n/i != n && n/i != i)
                    subSet[subCnt ++] = str.substr(0, n/i);
            }
        }
    }
    
    bool isRepeat(string &ptn, string &s){
        int n = s.size(), m = ptn.size();
        int i = m, j = 0;
        for(; i < n; ++ i, j = (j + 1)%m){
            if(s[i] != ptn[j])
                return false;
        }
        return true;
    }
};

/*
*
* Tag: String (KMP)
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        if(str.size() <= 1)
            return false;
        vector<int> nxt(str.size(), 0);
        for(int i = 1, j = 0; i < str.size(); ++ i){
            while(j > 0 && str[j] != str[i])
                j = nxt[j - 1];
            if(str[j] == str[i])
                nxt[i] = ++ j;
        }
        return nxt[str.size() - 1] && str.size()%(str.size() - nxt[str.size() - 1]) == 0;
    }
};
