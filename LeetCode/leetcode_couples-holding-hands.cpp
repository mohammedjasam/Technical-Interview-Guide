/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        if(row.size()&1 == 1){
            return -1;
        }
        
        vector<int> indexOfPeople(row.size(), 0);
        for(int i = 0; i < row.size(); ++ i){
            indexOfPeople[row[i]] = i;
        }
        
        int ans = 0;
        for(int i = 0; i < row.size(); i += 2){
            if(isCouple(row[i], row[i + 1])){
                continue;
            }
            
            if(isCouple(row[i + 1], row[i + 2])){
                swap(indexOfPeople[row[i]], indexOfPeople[row[i + 2]]);
                swap(row[i], row[i + 2]);
            } else {
                int people = findPeopleToFormCouple(row[i]);
                int index = indexOfPeople[people];
                swap(indexOfPeople[row[i + 1]], indexOfPeople[people]);
                swap(row[i + 1], row[index]);
            }
            
            ++ ans;
        }
        
        return ans;
    }
    
private:
    bool isCouple(int people1, int people2){
        return (people1&1 == 1 && people1 == people2 + 1) || (people2&1 == 1 && people2 == people1 + 1);
    }
    
    int findPeopleToFormCouple(int people){
        return people&1 == 1? people - 1 : people + 1;
    }
};
