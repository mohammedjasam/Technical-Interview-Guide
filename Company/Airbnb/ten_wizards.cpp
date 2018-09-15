/*
*
* Tag: Graph (Dijk)
* Time: O(m + nlgn) where m is the number of edges, and n is the number of nodes
* Space: O(n)
*/
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <ctype.h>
#include <climits>
#include <utility>
using namespace std;

class WizardManagement {
    
public:
  vector<int> findRelationshipPathBetweenWizards(vector<vector<int>> wizardsRelationship, int source, int destination) {
    int numOfWizards = wizardsRelationship.size();
    vector<int> ans;
    if(numOfWizards == 0 || source < 0 || source >= numOfWizards || destination < 0 || destination > numOfWizards) {
      return ans;
    }
    
    vector<int> path(numOfWizards);
    unordered_map<int,int> distance;
    for(int i = 0; i < numOfWizards; ++ i){
      path[i] = -1;
      distance[i] = INT_MAX;
    }
    distance[source] = 0;
    
    map<int, unordered_set<int>> pq;
    pq[0].insert(source);
    
    while(pq.size() > 0){
        auto pqIt = pq.begin();
        auto wizardIt = pqIt->second.begin();
        
        int curWizardId = *wizardIt;
        pqIt->second.erase(curWizardId);
        
        int curWizardDistance = pqIt->first;

        for(int nextWizardId : wizardsRelationship[curWizardId]) {
            int cost = (nextWizardId - curWizardId)*(nextWizardId - curWizardId);
            
            if(distance[curWizardId] + cost < distance[nextWizardId]) {
                if(pq.count(distance[nextWizardId]) != 0 && pq[distance[nextWizardId]].count(nextWizardId) != 0 ) {
                    pq[distance[nextWizardId]].erase(nextWizardId);
                    
                    if(pq[distance[nextWizardId]].size() == 0){
                        pq.erase(distance[nextWizardId]);
                    }
                }
                
                distance[nextWizardId] = distance[curWizardId] + cost;
                pq[distance[nextWizardId]].insert(nextWizardId);
                path[nextWizardId] = curWizardId;
            }
        }
        
        if(pqIt->second.size() == 0){
            pq.erase(curWizardDistance);
        }
        
    }
    
    int curId = destination;
    while(path[curId] != -1){
        ans.push_back(curId);
        curId = path[curId];
    }
    ans.push_back(source);
    reverse(ans.begin(), ans.end());
      
    return ans;
  }
};

int main() {
//    cout<<"Hi"<<endl;
    WizardManagement wm;
    vector<vector<int>> graph1 = {{1,2,3},{3},{},{}};
    vector<int> ans1 = wm.findRelationshipPathBetweenWizards(graph1, 0, 3);
    for(int wizard : ans1){
        cout<<wizard<<" ";
    }
    cout<<endl;
    
    vector<vector<int>> graph2 = {{1, 5, 9}, {2, 3, 9}, {4}, {}, {}, {9}, {}, {}, {}, {}};
    vector<int> ans2 = wm.findRelationshipPathBetweenWizards(graph2, 0, 9);
    for(int wizard : ans2){
        cout<<wizard<<" ";
    }
    cout<<endl;
    
    return 0;
}
