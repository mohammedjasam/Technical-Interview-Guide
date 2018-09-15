/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    int calPoints(vector<string>& ops) {
        int ans = 0;
        if(ops.size() == 0){
            return ans;
        }
        
        vector<int> rounds(ops.size(), 0);
        int numOfValidRounds = 0;
        for(string op : ops){
            int value = 0;
            if(op == "C"){
                -- numOfValidRounds;
                continue;
            } 
            
            if( op == "D" ){
                value = 2*lastNumOfValidRoundsPoints( rounds, numOfValidRounds, 1 );
            } else if( op == "+" ){
                value = lastNumOfValidRoundsPoints( rounds, numOfValidRounds, 1 ) + lastNumOfValidRoundsPoints( rounds, numOfValidRounds, 2 );
            } else {
                value = stoi( op );
            }
            
            rounds[numOfValidRounds ++] = value;
        }
        
        return accumulate(rounds.begin(), rounds.begin() + numOfValidRounds, 0);
    }
    
private:
    int lastNumOfValidRoundsPoints( vector<int> &rounds, int numOfValidRounds, int numOfRounds ){
        return numOfValidRounds >= numOfRounds ? rounds[numOfValidRounds - numOfRounds] : 0;
    }
};
