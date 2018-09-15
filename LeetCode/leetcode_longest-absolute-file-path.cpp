/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    /**
     * @param input an abstract file system
     * @return return the length of the longest absolute path to file
     */
    int lengthLongestPath(string& input) {
        int ans = 0;
        if(input.size() == 0){
            return ans;
        }
        
        input +='\n';
        vector<int> dirNameLen(input.size(), 0);
        for(int i = 0; i < input.size(); ++ i) {
            int numOfLevel = 0;
            while(i < input.size() && input[i] == '\t'){
                ++ numOfLevel;
                ++ i;
            }
            
            bool isFile = false;
            int fileNameLen = 0;
            while(i < input.size() && input[i] != '\n') {
                if(input[i] == '.')
                    isFile = true;
                ++ fileNameLen;
                ++ i;
            }
            
            if(isFile) {
                ans = max(ans, dirNameLen[numOfLevel] + fileNameLen + numOfLevel);
            } else {
                dirNameLen[numOfLevel + 1] = dirNameLen[numOfLevel] + fileNameLen;
            }
        }
        
        return ans;
    }
};
