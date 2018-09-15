/*
*
* Tag: Hash
* Time: O(1)
* Space: O(1)
*/
class Solution {
public:
    Solution(){
        shortToLongUrlMapping.clear();
        srand (time(NULL));
    }
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string shortUrl('a',5);
        int idx = 0, randomVal = 0;
        while(shortToLongUrlMapping.find(shortUrl) != shortToLongUrlMapping.end()){
            randomVal = rand() % 62;
            if(randomVal >= 0 && randomVal < 26)
                shortUrl[idx] = ('A' + randomVal);
            else if(randomVal >= 26 && randomVal < 52)
                shortUrl[idx] = ('a' + (randomVal - 26));
            else
                shortUrl[idx] = ('0' + (randomVal - 52));
            idx = (idx + 1)%5;
        }
        shortToLongUrlMapping[shortUrl] = longUrl;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string longUrl = shortToLongUrlMapping.find(shortUrl) != shortToLongUrlMapping.end() ? shortToLongUrlMapping[shortUrl] : shortUrl;
        return longUrl;
    }
private:
    unordered_map<string,string> shortToLongUrlMapping;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
