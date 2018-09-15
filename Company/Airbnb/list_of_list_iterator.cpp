/*
*
* Tag: Design
* Time: Next: O(1); HashNext: O(n) where n is the number of nested vectors; remove: O(n)
* Space: O(1)
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <list>
#include <climits>
#include <cstdint>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <assert.h>
using namespace std;

class TwoDimensionVectorIterator {
private:
    vector<int> emptyVector;
    vector<vector<int>>::iterator rowIt, rowEnd;
    vector<int>::iterator columnIt, columnEnd;
public:
    TwoDimensionVectorIterator(vector<vector<int>>& vec2d){
        rowIt = vec2d.begin();
        rowEnd = vec2d.end();
        columnIt = emptyVector.end();
        columnEnd = rowIt->end();
    }
    
    int next(){
        return *columnIt;
    }
    
    bool hasNext(){
        bool isColumnItInited = false;
        if(columnIt == emptyVector.end()){
            columnIt = rowIt->begin();
            isColumnItInited = true;
        }
        
        bool isMovedToNextRow = isMovedToNewRowOfVec2d();
        
        if(rowIt == rowEnd || columnIt == columnEnd){
            return false;
        }
        
        if(!isMovedToNextRow){
            if(!isColumnItInited){
                ++ columnIt;
            }
            
            if(columnIt == columnEnd) {
                isMovedToNewRowOfVec2d();
            }
        }
        
        return rowIt != rowEnd && columnIt != columnEnd;
    }
    
    void remove(){
        if(columnIt == columnEnd && !hasNext()){
            return ;
        }
        
        rowIt->erase(columnIt);
        if(rowIt->size() == 0){
            columnIt = columnEnd;
        }
    }
    
private:
    bool isMovedToNewRowOfVec2d(){
        bool isMovedToNextRow = false;
        while(columnIt == columnEnd && rowIt != rowEnd){
            ++ rowIt;
            columnIt = rowIt->begin();
            columnEnd = rowIt->end();
            
            isMovedToNextRow = true;
        }
        
        return isMovedToNextRow;
    }
};

int main() {
    vector<vector<int>> test1 = {{0, 1}, {2,3}, {4,5}, {6, 7}, {8, 9, 10}, {11, 12}};
    TwoDimensionVectorIterator it1(test1);
    
    while(it1.hasNext()){
        cout<<it1.next()<<" ";
    }
    cout<<endl;
    
    vector<vector<int>> test2 = {{}, {1}, {}, {2,3}, {4,5}, {},{},{}, {6, 7}, {8, 9, 10}, {11, 12}};
    TwoDimensionVectorIterator it2(test2);
    
    while(it2.hasNext()){
        cout<<it2.next()<<" ";
    }
    cout<<endl;
    
    vector<vector<int>> test3 = {{}, {1}, {}, {2,3}, {4,5}, {},{},{}, {6, 7}, {8, 9, 10}, {11, 12}, {}, {}, {}, {}, {}};
    TwoDimensionVectorIterator it3(test3);
    
    assert( it3.hasNext() );
    cout<<it3.next()<<endl;
    it3.remove();
    it3.remove();
    it3.remove();
    
    while(it3.hasNext()){
        cout<<it3.next()<<" ";
    }
    cout<<endl;
    
    return 0;
}
