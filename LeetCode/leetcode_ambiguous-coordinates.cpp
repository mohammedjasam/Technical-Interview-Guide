/*
*
* Tag: Brute Force
* Time: O(n^3)
* Space: O(n^3)
*/
class Solution {
public:
    vector<string> ambiguousCoordinates(string S) {
        vector<string> ans;
        if(S.size() < 2){
            return ans;
        }
        
        string num = S.substr(1, S.size() - 2);
        for(int i = 1; i < num.size(); ++ i){
            string firstValue = num.substr(0, i), secondValue = num.substr(i);
            vector<string> coordinates = getAllCoordinatesFor(firstValue, secondValue);
            ans.insert(ans.end(), coordinates.begin(), coordinates.end());
        }
        
        return ans;
    }

private:
    vector<string> getAllCoordinatesFor(string firstValue, string secondValue){
        vector<string> allFirstValues = getAllValuesFor(firstValue);
        vector<string> allSecondValues = getAllValuesFor(secondValue);
        
        vector<string> allCoordinates;
        if(allFirstValues.size() == 0 || allSecondValues.size() == 0){
            return allCoordinates;
        }
        
        for(string first : allFirstValues){
            for(string second : allSecondValues){
                string coordinate = "("+first+", "+second+")";
                allCoordinates.push_back(coordinate);
            }
        }
        
        return allCoordinates;
    }
    
    vector<string> getAllValuesFor(string str){
        int value = stoi(str);
        
        vector<string> allValues;
        if(value == 0){
            if(str.size() == 1){
                allValues.push_back(str);
            }
            
            return allValues;
        }
        
        
        if(isValidInteger(str)){
            allValues.push_back(str);
        }
        
        for(int i = 1; i < str.size(); ++ i){
            string integer = str.substr(0, i), decimal = str.substr(i);
            
            if( !isValidInteger(integer) || !isValidDecimal(decimal) ){
                break;
            }
            
            string res = integer + "." + decimal;
            allValues.push_back(res);
        }
        
        return allValues;
    }
    
    bool isValidInteger(string str){
        int value = stoi(str);
        if( (value == 0 && str.size() > 1) || (value > 0 && str[0] == '0')){
            return false;
        }
        
        return true;
    }
    
    bool isValidDecimal(string str){
        int value = stoi(str);
        return value > 0 && str[str.size() - 1] != '0';
    }
};
