/*
*
* Tag: Hash
* Time: O(1)
* Space: O(1)
*/
class Solution {
public:
    string originalDigits(string s) {
        string ans = "", tmp = "";
        if(s.size() == 0)
            return ans;
        init();
        vector<int> lettercnt(26, 0), digitcnt(10, 0);
        for(int i = 0; i < s.size(); ++ i){
            ++ lettercnt[s[i] - 'a'];
        }
        for(int i = 0; i < 10; ++ i){
            getDigit(digitorder[i], lettercnt, digitcnt);
        }
        for(int i = 0; i < 10; ++ i){
            while(digitcnt[i] > 0){
                -- digitcnt[i];
                tmp = ('0'+i);
                ans += tmp;
            }
        }
        return ans;
    }
private:
    void init(){
        dict.clear();
        dict[0] = "zero";
        dict[1] = "one";
        dict[2] = "two";
        dict[3] = "three";
        dict[4] = "four";
        dict[5] = "five";
        dict[6] = "six";
        dict[7] = "seven";
        dict[8] = "eight";
        dict[9] = "nine";
    }
    
    void decreaseCnt(int key, vector<int> &lettercnt){
        string val = dict[key];
        int idx = 0;
        for(int i = 0; i < val.size(); ++ i){
            idx = val[i] - 'a';
            -- lettercnt[idx];
        }
    }
    
    void getDigit(int digit, vector<int> &lettercnt, vector<int> &digitcnt){
        switch(digit){
            case 0:
                while(lettercnt[25] > 0){
                    decreaseCnt(digit, lettercnt);
                    ++ digitcnt[digit];
                }
                break;
            case 1:
                while(lettercnt[14] > 0){
                    decreaseCnt(digit, lettercnt);
                    ++ digitcnt[digit];
                }
                break;
            case 2:
                while(lettercnt[22] > 0){
                    decreaseCnt(digit, lettercnt);
                    ++ digitcnt[digit];
                }
                break;
            case 3:
                while(lettercnt[19] > 0){
                    decreaseCnt(digit, lettercnt);
                    ++ digitcnt[digit];
                }
                break;
            case 4:
                while(lettercnt[20] > 0){
                    decreaseCnt(digit, lettercnt);
                    ++ digitcnt[digit];
                }
                break;
            case 5:
                while(lettercnt[5] > 0){
                    decreaseCnt(digit, lettercnt);
                    ++ digitcnt[digit];
                }
                break;
            case 6:
                while(lettercnt[23] > 0){
                    decreaseCnt(digit, lettercnt);
                    ++ digitcnt[digit];
                }
                break;
            case 7:
                while(lettercnt[18] > 0){
                    decreaseCnt(digit, lettercnt);
                    ++ digitcnt[digit];
                }
                break;
            case 8:
                while(lettercnt[6] > 0){
                    decreaseCnt(digit, lettercnt);
                    ++ digitcnt[digit];
                }
                break;
            case 9:
                while(lettercnt[8] > 0){
                    decreaseCnt(digit, lettercnt);
                    ++ digitcnt[digit];
                }
                break;
        }
    }
private:
    int digitorder[10]={0,2,6,8,4,1,5,7,9,3};
    unordered_map<int,string> dict;
};
