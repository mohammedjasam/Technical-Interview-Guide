/*
*
* Tag: Data Structure
* Time: O(1)
* Space: O(1)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
using namespace std;

class Queue {
private:
    list<vector<int>> que;
    list<vector<int>>::iterator head, tail;
    vector<int>::iterator queHeadIt, queTailIt;
    int blockSize, curUsedBlockSize;
    int queSize;
    
public:
    Queue(int _blockSize){
        blockSize = _blockSize;
        
        vector<int> arrayBlock(blockSize);
        que.push_back(arrayBlock);
        
        head = tail = que.begin();
        queHeadIt = head->begin();
        queTailIt = tail->begin();
        curUsedBlockSize = 0;
        queSize = 0;
    }
    
    void push(int val){
        if(curUsedBlockSize == blockSize){
            vector<int> arrayBlock(blockSize);
            que.push_back(arrayBlock);
            
            ++ tail;
            curUsedBlockSize = 0;
            queTailIt = tail->begin();
        }
        
        *queTailIt = val;
        ++ queTailIt;
        ++ curUsedBlockSize;
        ++ queSize;
    }
    
    int front(){
        if(size() <= 0){
            //FIXME: throw an exception here
            return -1;
        }
        
        return *queHeadIt;
    }
    
    void pop(){
        ++ queHeadIt;
        if(queHeadIt == head->end()){
            ++ head;
            queHeadIt = head->begin();
        }
        
        -- queSize;
    }
    
    int size(){
        return queSize;
    }
};

int main() {
    Queue q(2);
    for(int i = 1; i <= 5; ++ i){
        q.push(i);
        printf("size of que : %d\n", q.size());
    }
    
    while(q.size() > 0){
        printf("front of element: %d, and size of que is %d\n", q.front(), q.size());
        q.pop();
    }
    return 0;
}
