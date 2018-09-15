/*
*
* Tag: Stack (Data Structure)
* Time: O(n)
* Space: O(n)
*/

class StockSpanner {
private:
    stack<pair<int,int>> stockSpans;
    
public:  
    int next(int price) {
        int span = 1;
        while(!stockSpans.empty()){
            pair<int,int> lastStockSpan = stockSpans.top();
            if(lastStockSpan.first > price){
                break;
            }
            
            span += lastStockSpan.second;
            stockSpans.pop();
        }
        stockSpans.push(make_pair(price, span));
        
        return span;
    }
};
