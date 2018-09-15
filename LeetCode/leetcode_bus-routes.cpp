/*
*
* Tag: Graph
* Time: O(m + n*m)
* Space: O(m)
*/
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if(routes.size() == 0 || S == T){
            return 0;
        }
        
        queue<pair<int,int>> q;
        unordered_map<int, unordered_set<int>> busesOfStop;
        vector<bool> usedBus(routes.size(), false);
        for(int i = 0; i < routes.size(); ++ i){
            for(int stop : routes[i]){
                if(stop == S){
                    q.push(make_pair(i, 1));
                    usedBus[i] = true;
                }
                
                busesOfStop[stop].insert(i);
            }
        }
        
        while(!q.empty()){
            pair<int,int> busState = q.front();
            q.pop();

            int curBus = busState.first;
            int numOfBuses = busState.second;
            for(int stop : routes[curBus]){
                if(stop == T){
                    return numOfBuses;
                }
                
                for(int bus : busesOfStop[stop]){
                    if(!usedBus[bus]){
                        usedBus[bus] = true;
                        q.push(make_pair(bus, numOfBuses + 1));
                    }
                }
            }
        }
        
        return -1;
    }
};
