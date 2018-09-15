/*
*
* Tag: Binary Search
* Time: O(nlgm) where m is the largest distance between adjacent stations.
* Space: O(1)
*/
class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) {        
        double l = 0, r = INT_MIN;
        for(int i = 0; i < stations.size() - 1; ++ i){
            r = max(r, double(stations[i + 1] - stations[i]));
        }
        
        while(l + 0.000001 < r){
            double mid = (l + r)/2;
            if(canAddKStations(stations, mid, K)){
                r = mid;
            } else {
                l = mid;
            }
        }
        
        return l;
    }
    
private:
    bool canAddKStations(vector<int>& stations, double mid, int k){
        int cntOfStations = 0;
        for(int i = 0; i < stations.size() - 1; ++ i){
            int distanceBetweenStations = stations[i + 1] - stations[i];
            int stationsAdded = distanceBetweenStations/mid;
            
            cntOfStations += stationsAdded;
        }
        
        return cntOfStations <= k;
    }
    
};
