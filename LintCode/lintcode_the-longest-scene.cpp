/**
*
* Tag: Data Structure + Sort
* Time: O(nlgn)
* Space: O(n)
*/
class Solution {
public:
    /**
     * @param str: The scene string
     * @return: Return the length longest scene
     */
    int getLongestScene(string &str) {
        int ans = 0;
        if(str.size() == 0){
            return 0;
        }
        
        unordered_map<char, pair<int,int>> boundsOfCharacter;
        for(int i = 0; i < str.size(); ++ i){
            if(boundsOfCharacter.count(str[i]) == 0){
                boundsOfCharacter[str[i]] = make_pair(i, i);
            }
            boundsOfCharacter[str[i]].second = max(boundsOfCharacter[str[i]].second, i);
        }
        
        vector<pair<int,int>> boundsOfAllCharacters;
        for(auto i = boundsOfCharacter.begin(); i != boundsOfCharacter.end(); ++ i){
            boundsOfAllCharacters.push_back(i->second);
        }
        
        sort(boundsOfAllCharacters.begin(), boundsOfAllCharacters.end(), cmp);
        int curLeftBound = boundsOfAllCharacters[0].first;
        int curRightBound = boundsOfAllCharacters[0].second;
        for(pair<int,int> curBound : boundsOfAllCharacters){
            ans = max(ans, curBound.second - curBound.first + 1);
            if( curRightBound > curBound.first ){
                curRightBound = max(curRightBound, curBound.second);
            } else {
                curLeftBound = curBound.first;
                curRightBound = curBound.second;
            }
            
            ans = max(ans, curRightBound - curLeftBound + 1);
        }
        
        return ans;
    }

private:
    struct comparator{
      bool operator() (const pair<int,int> &a, const pair<int,int> &b){
          return a.first == b.first ? a.second < b.second : a.first < b.first;
      }
    }cmp;
};
