/*
*
* Tag: Design
* Time: Next: O(n); HashNext: O(1). n is the number of rows.
* Space: O(1)
*/
class Vector2D {
private:
    vector<vector<int>>::iterator rowIt, rowEnd;
    vector<int>::iterator columnIt, columnEnd;
    
public:
    Vector2D(vector<vector<int>>& vec2d) {
        rowIt = vec2d.begin();
        rowEnd = vec2d.end();
        if(vec2d.size() == 0){
            return ;
        }
        
        columnIt = vec2d[0].begin();
        columnEnd = vec2d[0].end();
        if(columnIt == columnEnd){
            moveToNextElement();
        }
    }

    int next() {
        int res = *columnIt;
        moveToNextElement();
        
        return res;
    }

    bool hasNext() {
        return rowIt != rowEnd;
    }
    
private:
    void moveToNextElement(){  
        if(columnIt != columnEnd){
            ++ columnIt;
        }
        
        while(rowIt != rowEnd && columnIt == columnEnd){
            ++ rowIt;
            if(rowIt == rowEnd){
                return ;
            }
            
            columnIt = rowIt->begin();
            columnEnd = rowIt->end();
        }
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
