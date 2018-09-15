/*
*
* Tag: String
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        string replaceString = "";
        if(S.size() == 0 || indexes.size() == 0 || sources.size() != targets.size()){
            return S;
        }
        
        unordered_map<int, pair<string,string>> sourceTargetStringsOfIndex;
        for(int i = 0; i < indexes.size(); ++ i){
            sourceTargetStringsOfIndex[indexes[i]] = make_pair(sources[i], targets[i]);
        }
        
        for(int i = 0; i < S.size(); ++ i){
            if(sourceTargetStringsOfIndex.count(i) == 0){
                replaceString += S[i];
                continue;
            }
            
            string source = sourceTargetStringsOfIndex[i].first;
            string target = sourceTargetStringsOfIndex[i].second;
            if(!canSourceFound(S, source, i)){
                replaceString += S[i];
                continue;
            }
            replaceString += target;
            i += (source.size() - 1);
        }
        
        return replaceString;
    }
private:
    bool canSourceFound(string S, string source, int startIndex){
        for(int i = startIndex, j = 0; i < S.size() && j < source.size(); ++ i, ++ j){
            if(S[i] != source[j]){
                return false;
            }
        }
        
        return true;
    }
};
