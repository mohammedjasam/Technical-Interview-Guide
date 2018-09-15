/*
*
* Tag: DFS
* Time: O(n^m) n is the length of bottom string and m is the number of allowed strings
* Space: O(n^m)
*/
class Solution {
private:
    unordered_map<char, unordered_map<char,unordered_set<char>>> allowedColorCombinations;
public:
    bool pyramidTransition(string bottom, vector<string>& alloweds) {
        if(bottom.size() == 1){
            return true;
        }
        
        init(alloweds);
        
        unordered_set<string> nextLayers = builAllPossibleNextLayersFor(bottom);
        for(string nextLayer : nextLayers){
            if(pyramidTransition(nextLayer, alloweds) ){
                return true;
            }
        }
        
        return false;
    }
private:
    void init(vector<string>& alloweds){
        if(allowedColorCombinations.size() != 0){
            return ;
        }
        
        for(string allowed : alloweds){
            allowedColorCombinations[allowed[0]][allowed[1]].insert(allowed[2]);
        }
    }
    
    unordered_set<string> builAllPossibleNextLayersFor(string bottom){
        unordered_set<string> allPossibleNextLayers;
        
        string nextLayer = "";
        buildNextLayer(allPossibleNextLayers, nextLayer, bottom, 0);
        
        return allPossibleNextLayers;
    }
    
    void buildNextLayer(unordered_set<string> &allPossibleNextLayers, string nextLayer, string bottom, int idx){
        if(idx >= bottom.size() - 1){
            allPossibleNextLayers.insert(nextLayer);
            return ;
        }
        
        for(char color : allowedColorCombinations[bottom[idx]][bottom[idx + 1]]){
            string newNextLayer = nextLayer + color;
            buildNextLayer(allPossibleNextLayers, newNextLayer, bottom, idx + 1);
        }
    }
};
