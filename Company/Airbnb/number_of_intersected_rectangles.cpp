/*
*
* Tag: Union Find
* Time: O(n^3)
* Space: O(n)
*/

#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <cmath>
#include <ctype.h>
#include <climits>
#include <utility>
using namespace std;

class intersectedRectanglesSet {
private:
    unordered_map<int,int> parentOfRectangles;
public:
    int countIntersection(vector<vector<pair<int,int>>> rectangles){
        int ans = 0;
        if(rectangles.size() == 0){
            return ans;
        }
        
        init(rectangles.size());
        
        for(int i = 0; i < rectangles.size() - 1; ++ i){
            for(int j = i + 1; j < rectangles.size(); ++ j){
                if(!areOverlapped(rectangles[i], rectangles[j])) {
                    //cout<<"no: "<<i<<" "<<j<<endl;
                    continue;
                }
                
//                cout<<findParentOf(i)<<" vs "<<findParentOf(j)<<endl;
                if(findParentOf(i) == findParentOf(j)) {
//                    cout<<"same parent: "<<i<<" "<<j<<endl;
                    continue;
                }
                
//                cout<<"union: "<<i<<" "<<j<<endl;
                unionSet(i, j);
            }
        }
        
        for(auto it = parentOfRectangles.begin(); it != parentOfRectangles.end(); ++ it) {
            if(it->second < 0) {
                ++ ans;
            }
        }
        return ans;
    }

private:
    void init(int n){
        parentOfRectangles.clear();
        
        for(int i = 0; i < n; ++ i){
            parentOfRectangles[i] = -1;
        }
    }
    
    bool areOverlapped(vector<pair<int,int>> a, vector<pair<int,int>> b){
        return a[0].first < b[1].first && b[0].first < a[1].first && a[0].second < b[1].second && b[0].second < a[1].second;
    }
    
    int findParentOf(int node){
        int parent = node;
        
        for(; parentOfRectangles[parent] >= 0; parent = parentOfRectangles[parent]);
        
        while(node != parent){
            int nextNode = parentOfRectangles[node];
            parentOfRectangles[node] = parent;
            node = nextNode;
        }
        
        return parent;
    }
    
    void unionSet(int a, int b){
        int parentOfA = findParentOf(a), parentOfB = findParentOf(b);
        int rank = parentOfRectangles[parentOfA] + parentOfRectangles[parentOfB];
        
        if(parentOfRectangles[parentOfA] <= parentOfRectangles[parentOfB]) {
            parentOfRectangles[parentOfB] = parentOfA;
            parentOfRectangles[parentOfA] = rank;
        } else {
            parentOfRectangles[parentOfA] = parentOfB;
            parentOfRectangles[parentOfB] = rank;
        }
        
        return ;
    }
};

int main() {
//    cout<<"Hi"<<endl;
    intersectedRectanglesSet irs;
    
    vector<vector<pair<int,int>>> rect1 = {{make_pair(0,0), make_pair(1,1)}};
    int ans1 = irs.countIntersection(rect1);
    cout<<ans1<<endl;
    
    vector<vector<pair<int,int>>> rect2 = {
        {make_pair(0,0), make_pair(3,3)},
        {make_pair(1,1), make_pair(5,5)}
    };
    int ans2 = irs.countIntersection(rect2);
    cout<<ans2<<endl;
    
    vector<vector<pair<int,int>>> rect3 = {
        {make_pair(0,0), make_pair(3,3)},
        {make_pair(1,1), make_pair(5,5)},
        {make_pair(100,100), make_pair(900,900)}
    };
    int ans3 = irs.countIntersection(rect3);
    cout<<ans3<<endl;
    
    vector<vector<pair<int,int>>> rect4 = {};
    int ans4 = irs.countIntersection(rect4);
    cout<<ans4<<endl;
    
    vector<vector<pair<int,int>>> rect5 = {
        {make_pair(-3, -2), make_pair(2, 1)},
        {make_pair(10, 8), make_pair(15, 10)},
        {make_pair(1, 0), make_pair(7, 4)},
        {make_pair(12, 9), make_pair(16, 12)},
        {make_pair(-2, -1), make_pair(5, 3)}
    };
    int ans5 = irs.countIntersection(rect5);
    cout<<ans5<<endl;
    return 0;
}
