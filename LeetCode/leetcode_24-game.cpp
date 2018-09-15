/*
*
* Tag: DFS
* Time: O(1) The number of cards is fixed ...
* Space: O(1)
*/

class Solution {
private:
    const double EPS = 1e-9;
    vector<string> allOperatorsCombinations;
    string allOprators = "+-*/";
public:
    Solution(){
        findAllOperatorsCombinations();
    }
    
    bool judgePoint24(vector<int>& nums) {        
        sort(nums.begin(), nums.end());
        do{
            if(isAbleToGet24FromPermutation(nums)){
                return true;
            }
        }while(next_permutation(nums.begin(), nums.end()));
        
        return false;
    }
    
private:
    void findAllOperatorsCombinations(){        
        string operators = "";
        dfsToGetOperatorsCombination(operators, 0);
    }
    
    void dfsToGetOperatorsCombination(string operators, int numOfOperators){
        if(numOfOperators == 3){
            allOperatorsCombinations.push_back(operators);
            return ;
        }
        
        for(int i = 0; i < 4; ++ i){            
            dfsToGetOperatorsCombination(operators + allOprators[i], numOfOperators + 1);            
        }
    }
    
    bool isAbleToGet24FromPermutation(vector<int>& nums){
        vector<double> numsForOperation(nums.begin(), nums.end());
        
        for(string operators : allOperatorsCombinations){
            if(canGet24From(numsForOperation, operators)){
                return true;
            }
        }
        
        return false;
    }
    
    bool canGet24From(vector<double>& nums, string &operators){
        if(nums.size() == 1){
            return fabs(nums[0] - 24) < EPS;
        }
        
        for(int i = 0; i < nums.size() - 1; ++ i){
            vector<double> nextNums;
            string nextOperators = "";
            for(int j = 0; j < i; ++ j){
                nextNums.push_back(nums[j]);
                nextOperators += operators[j];
            }
            
            if(operators[i] == '/' && fabs(nums[i + 1] - 0) < EPS) {
                continue;
            }
            nextNums.push_back(calculate(nums[i], nums[i + 1], operators[i]));
            
            for(int j = i + 2; j < nums.size(); ++ j){
                nextNums.push_back(nums[j]);
                nextOperators += operators[j - 1];
            }
            
            if(canGet24From(nextNums, nextOperators)){
                return true;
            }
        }
        
        return false;
    }
    
    double calculate(double a, double b, char op){
        switch(op){
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
        }
        
        return 1.0;
    }
};
