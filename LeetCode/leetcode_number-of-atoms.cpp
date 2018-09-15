/*
*
* Tag: Stack (Data Structure)
* Time: O(n^2)
* Space: O(n)
*/
class Solution {
private:
    map<string,int> atomsCount;
    
public:
    string countOfAtoms(string formula) {
        atomsCount.clear();
        
        string atomFormula = "("+formula+")";
        stack<unordered_map<string,int>> stackOfFormulars;
        for(int i = 0; i < atomFormula.size(); ++ i){
            if(atomFormula[i] == '('){
                unordered_map<string,int> countOfAtoms;
                stackOfFormulars.push(countOfAtoms);
                continue;
            }
            
            if(atomFormula[i] == ')'){
                int count = getFormulaCount(atomFormula, i);
                
                unordered_map<string,int> curCountOfAtoms = stackOfFormulars.top();
                stackOfFormulars.pop();
                
                if(stackOfFormulars.empty()){
                    for(auto it = curCountOfAtoms.begin(); it != curCountOfAtoms.end(); ++ it){
                        curCountOfAtoms[it->first] = it->second*count;
                    }
                    stackOfFormulars.push(curCountOfAtoms);
                    
                    continue;
                }
                
                unordered_map<string,int> lastCountOfAtoms = stackOfFormulars.top();
                stackOfFormulars.pop();
                
                for(auto it = curCountOfAtoms.begin(); it != curCountOfAtoms.end(); ++ it){
                    lastCountOfAtoms[it->first] += it->second*count;
                }
                
                stackOfFormulars.push(lastCountOfAtoms);
            } else {
                pair<string,int> atomCount = getAtomCounts(atomFormula, i);
                
                unordered_map<string,int> countOfAtoms = stackOfFormulars.top();
                stackOfFormulars.pop();
                countOfAtoms[atomCount.first] += atomCount.second;
                stackOfFormulars.push(countOfAtoms);                
            }
        }
        
        if(!stackOfFormulars.empty()){
            unordered_map<string,int> countOfAtoms = stackOfFormulars.top();
            stackOfFormulars.pop();
            
            for(auto it = countOfAtoms.begin(); it != countOfAtoms.end(); ++ it){
                atomsCount[it->first] = it->second;
            }
        }
        
        string ans = "";
        for(auto it = atomsCount.begin(); it != atomsCount.end(); ++ it){
            ans += it->first;
            if(it->second > 1){
                ans += to_string(it->second);
            }
        }
        return ans;
    }
    
private:
    pair<string,int> getAtomCounts(string formula, int &index){
        string atom = "";
        int count = 0;
        
        atom += formula[index ++];
        while(index < formula.size() && formula[index] >= 'a' && formula[index] <= 'z'){
            atom += formula[index];
            ++ index;
        }
        
        if(index >= formula.size() || (formula[index] < '0' || formula[index] > '9') ) {
            count = 1;
        } else{
            while(index < formula.size() && formula[index] >= '0' && formula[index] <= '9') {
                count = count*10 + (formula[index] - '0');
                ++ index;
            }
        }
        
        -- index;
        return make_pair(atom, count);
    }
    
    int getFormulaCount(string formula, int &index){
        int count = 0;
        
        ++ index;
        if(index >= formula.size() || (formula[index] < '0' || formula[index] > '9')){
            -- index;
            return 1;
        }
        
        while(index < formula.size() && formula[index] >= '0' && formula[index] <= '9'){
            count = count*10 + (formula[index] - '0');
            ++ index;
        }
        
        -- index;
        return count;
    }
};
