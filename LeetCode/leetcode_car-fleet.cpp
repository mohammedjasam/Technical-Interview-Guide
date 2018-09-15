/*
*
* Tag: stack
* Time: O(nlgn)
* Space: O(n)
*/
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if(target == 0 || position.size() == 0){
            return position.size();
        }
        
        vector<pair<int,int>> cars(position.size());
        for(int i = 0; i < position.size(); ++ i){
            cars[i] = make_pair(position[i], speed[i]);
        }
        sort(cars.begin(), cars.end(), cmp);
        
        stack<pair<int,int>> carFleets;
        for(pair<int,int> car : cars){
            if(!carFleets.empty() && canMergeToCarFleet(carFleets.top(), car, target)){
                continue;
            }
            
            carFleets.push(car);
        }
        
        return carFleets.size();
    }
    
private:
    bool canMergeToCarFleet(pair<int,int> carFleet, pair<int,int> car, int target){
        if(carFleet.second > car.second){
            return false;
        }
        
        if(carFleet.first > car.first && carFleet.second == car.second){
            return false;
        }
        
        return ((long long)carFleet.first - car.first)*carFleet.second <= ((long long)car.second - carFleet.second)*(target - carFleet.first);
    }
    
private:
    struct carComparator {
        bool operator() (const pair<int,int> &a, const pair<int,int> &b){
            return a.first == b.first ? b.second < a.second : b.first < a.first;
        }
    }cmp;
};
