/*
*
* Tag: Design
* Time: Precompute: O(n), hasNext: O(1), next: O(1)
* Space: O(n)
*/
class StringIterator {
private:
    const char DEFAULT_LETTER = ' ';
    vector<pair<char,long long>> originalString;
    int curIndex;
public:
    StringIterator(string compressedString) {
        curIndex = 0;
        originalString = decompressString( compressedString );
    }
    
    char next() {
        return curIndex < originalString.size() ? getCurrentChar() : DEFAULT_LETTER;
    }
    
    bool hasNext() {
        return curIndex < originalString.size();
    }
    
private:
    vector<pair<char,long long>> decompressString( string compressedString ){
        vector<pair<char,long long>> ans;
        for(int index = 0; index < compressedString.size(); ++ index){
            char curChar = compressedString[index];
            if(curChar >= '0' && curChar <= '9'){
                continue;
            }
            
            long long numOfChars = getNumOfChars(index + 1, compressedString);
            ans.push_back(make_pair(curChar, numOfChars));
        }
        return ans;
    }
    
    long long getNumOfChars(int startIndex, string str){
        long long num = 0;
        for(int i = startIndex; i < str.size(); ++ i){
            if(str[i] < '0' || str[i] > '9')
                break;
            num = (num*10) + (int)(str[i] - '0');
        }
        return num;
    }
    
    char getCurrentChar(){
        char ans = originalString[curIndex].first;
        -- originalString[curIndex].second;
        if(originalString[curIndex].second == 0){
            ++ curIndex;
        }
        return ans;
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * bool param_2 = obj.hasNext();
 */
