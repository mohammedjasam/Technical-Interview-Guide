/*
*
* Tag: Heap (Greedy)
* Time: O(nlgn)
* Space: O(n)
*/
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        if(quality.size() == 0 || wage.size() == 0 || K == 0){
            return 0;
        }
        
        vector<vector<double>> workers;
        for(int i = 0; i < quality.size(); ++ i){
            workers.push_back({(double)(wage[i])/quality[i], (double)quality[i] });
        }
        sort(workers.begin(), workers.end());
        
        double res = 9999999999, sumOfQuality = 0;
        priority_queue<int> pq;
        for(vector<double> worker : workers){
            sumOfQuality += worker[1];
            pq.push(worker[1]);
            
            if(pq.size() > K){
                sumOfQuality -= pq.top();
                pq.pop();
            }
            if(pq.size() == K){
                res = min(res, sumOfQuality*worker[0]);
            }
        }
        
        return res;
    }
};
