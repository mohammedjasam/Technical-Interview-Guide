/*
*
* Tag: Data Structure
* Time: O(1)
* Space: O(n)
*/
class MovingAverage {
private:
    vector<int> arr;
    int id;
    int sum, n;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        arr.resize(size);
        id = 0;
        sum = 0;
        n = 0;
    }
    
    double next(int val) {
        if(n < arr.size()){
            arr[id] = val;
            id = (id + 1)%arr.size();
            sum += val;
            ++ n;
        }else{
            sum -= arr[id];
            arr[id] = val;
            sum += val;
            id = (id + 1)%arr.size();
        }
        
        return (double)sum/(double)n;
    }
};
