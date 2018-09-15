/*
*
* Tag: Implementation
* Time: O(n*rows)
* Space: O()
*/
class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int sum = 0, ans = 0, idx = 0;
        for(int i = 0; i < sentence.size(); ++ i)
            sum += sentence[i].size();
        int remain = 0;
        for(int i = 0; i < rows; ++ i){
            remain = cols + 1;
            while(idx < sentence.size() && sentence[idx].size() + 1 <= remain)
                remain -= sentence[idx ++].size() + 1;
            while(idx >= sentence.size()){
                idx = 0;
                ans = ans + 1 + remain/(sum + sentence.size());
                remain %= sum + sentence.size();
                while(idx < sentence.size() && sentence[idx].size() + 1 <= remain)
                    remain -= sentence[idx ++].size() + 1;
            }
        }
        return ans;
    }
};
