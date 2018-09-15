/*
*
* Tag: Graph
* Time: O(ke) e is the number of edges
* Space: O(n)
*/
class Solution {
private:
    const int MAX_PRICE = INT_MAX>>1;
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        if(n == 0 || flights.size() == 0){
            return -1;
        }
        
        vector<vector<int>> cheapestPrice(2, vector<int>(n, MAX_PRICE));
        cheapestPrice[0][src] = cheapestPrice[1][src] = 0;
        
        for(int i = 0; i <= K; ++ i){
            for(vector<int> flight : flights){
                cheapestPrice[i&1][flight[1]] = min(cheapestPrice[i&1][flight[1]], cheapestPrice[~i&1][flight[0]] + flight[2]);
            }
        }
        
        return cheapestPrice[K&1][dst] == MAX_PRICE ? -1 : cheapestPrice[K&1][dst];
    }
};
