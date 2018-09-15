/*
*
* BUG FIX
* Tag: Greedy
* Time: O(nlgn)
* Space: O(n)
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <assert.h>
using namespace std;

class PriceManager {
public:
    vector<double> getRoundedPrices(vector<double> &prices){
        vector<double> ans;
        if(prices.size() == 0){
            return ans;
        }
        
        ans.resize(prices.size());
        vector<pair<int,double>> priceWithDiff;
        int floorSum = 0;
        double roundedSum = 0;
        for(double price : prices){
            int floorPrice = floor(price);
            int ceilingPrice = ceil(price);
            roundedSum += price;
            floorSum += floorPrice;
            
            priceWithDiff.push_back(make_pair(ceilingPrice, ceilingPrice - price));
        }
        
        sort(priceWithDiff.begin(), priceWithDiff.end(), cmp);
        
        int diff = round(roundedSum) - floorSum;
        int indexOfPrice = 0;
        for(; indexOfPrice < priceWithDiff.size(); ++ indexOfPrice){
            //cout<<priceWithDiff[indexOfPrice].first<<" "<<priceWithDiff[indexOfPrice].second<<endl;
            ans[indexOfPrice] = priceWithDiff[indexOfPrice].first - 1;
            if(diff > 0 && priceWithDiff[indexOfPrice].second > 0 || fabs(priceWithDiff[indexOfPrice].second - 0) < 0.0000001){
                ans[indexOfPrice] = priceWithDiff[indexOfPrice].first;
                
                if(diff > 0 && priceWithDiff[indexOfPrice].second > 0){
                    -- diff;
                }
            }
        }
        
        return ans;
    }
private:
    struct priceComparator {
        bool operator() (const pair<int,double> &a, const pair<int,double> &b){
            return a.second < b.second;
        }
    }cmp;
};

int main() {
    PriceManager pm;
    vector<double> prices1 = {1.2, 2.3, 3.4};
    vector<double> ans = pm.getRoundedPrices( prices1 );
    for(double price : ans){
        cout<<price<<" ";
    }
    cout<<endl;
    
    vector<double> prices2 = {1.2, 3.7, 2.3, 4.8};
    ans = pm.getRoundedPrices( prices2 );
    for(double price : ans){
        cout<<price<<" ";
    }
    cout<<endl;
    
    vector<double> prices3 = {1.2, 2.5, 3.6, 4.0}; //1.1 -> 1 2 4 4
    ans = pm.getRoundedPrices( prices3 );
    for(double price : ans){
        cout<<price<<" ";
    }
    cout<<endl;
    
    vector<double> prices4 = {1.2, 2.5, 3.6, 4.0};//1.1 -> 1 2 4 4; 
    ans = pm.getRoundedPrices( prices4 );
    for(double price : ans){
        cout<<price<<" ";
    }
    cout<<endl;
    
    vector<double> prices5 = {2.5, 2.3, 3.1, 6.5};  //1.4 -> 2 2 3 7; 3 6 2 3 
    ans = pm.getRoundedPrices( prices5 );
    for(double price : ans){
        cout<<price<<" ";
    }
    cout<<endl;
    
    vector<double> prices6 = {2.9, 2.3, 1.4, 3, 6};
    ans = pm.getRoundedPrices( prices6 );
    for(double price : ans){
        cout<<price<<" ";
    }
    cout<<endl;
    
    vector<double> prices7 = {-0.4, 1.3, 1.3, 1.3, 1.3, 1.3, 1.3, 1.3, 1.3, 1.3, 1.3};
    ans = pm.getRoundedPrices( prices7 );
    for(double price : ans){
        cout<<price<<" ";
    }
    assert(ans[0] == 0);
    cout<<endl;
    return 0;
}
