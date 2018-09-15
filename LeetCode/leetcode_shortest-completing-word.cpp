/*
*
* Tag: Hash
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> letterCountsOfLicensePlate(26, 0);
        updateLetterCountsOfWord(licensePlate, letterCountsOfLicensePlate);
        
        int minLengthOfWord = INT_MAX;
        string ans = "";
        for(string word : words){
            vector<int> letterCountsOfWord(26, 0);
            updateLetterCountsOfWord(word, letterCountsOfWord);
            if(canCompleteLicense(letterCountsOfLicensePlate, letterCountsOfWord)){
                if(minLengthOfWord > word.size()){
                    minLengthOfWord = word.size();
                    ans = word;
                }
            }
        }
        
        return ans;
    }
private:
    void updateLetterCountsOfWord(string word, vector<int> &letterCountsOfWord){
        for(char letter : word){
            if(isalpha(letter)){
                int key = (tolower(letter) - 'a');
                ++ letterCountsOfWord[key];
            }
        }
    }
    
    bool canCompleteLicense(vector<int> &letterCountsOfLicensePlate,  vector<int> &letterCountsOfWord){
        for(int i = 0; i < letterCountsOfLicensePlate.size(); ++ i){
            if(letterCountsOfLicensePlate[i] > letterCountsOfWord[i]){
                return false;
            }
        }
        
        return true;
    }
};
