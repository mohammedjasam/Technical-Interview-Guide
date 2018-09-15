/*
*
* Tag: DFS + Math
* Time: O(iter)
* Space: O(iter)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <assert.h>
using namespace std;

class HilbertCurve {
public:
    int getNumOfStepsToBackToOriginalPoint(int x, int y, int iter){
        if(iter == 0) {
            return 1;
        }
        
        int halfLen = 1<<(iter-1);
        int numOfPoints = 1<<(2*(iter - 1));
        
        if(x < halfLen && y < halfLen) {
            return getNumOfStepsToBackToOriginalPoint(y, x, iter - 1);
        } else if(x < halfLen && y >= halfLen) {
            return numOfPoints + getNumOfStepsToBackToOriginalPoint(x, y - halfLen, iter - 1);
        } else if(x >= halfLen && y >= halfLen) {
            return 2*numOfPoints + getNumOfStepsToBackToOriginalPoint(x - halfLen, y - halfLen, iter - 1);
        } else {
            return 3*numOfPoints + getNumOfStepsToBackToOriginalPoint(halfLen - y - 1, 2*halfLen - x - 1, iter - 1);
        }
    }
};

int main() {
    HilbertCurve hc;
    
    int ans = hc.getNumOfStepsToBackToOriginalPoint(1, 1, 2);
    assert(ans == 3);
    
    ans = hc.getNumOfStepsToBackToOriginalPoint(0, 1, 1);
    assert(ans == 2);
    
    ans = hc.getNumOfStepsToBackToOriginalPoint(2, 2, 2);
    assert(ans == 9);
    
    return 0;
}
