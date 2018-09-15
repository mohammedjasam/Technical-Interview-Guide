/*
*
* Tag: Binary Search
* Time: O(lgn)
* Space: O(1)
*/
// Forward declaration of ArrayReader class.
class ArrayReader;

class Solution {
private:
    const int OUT_OF_BOUND_SIGNAL = INT_MAX;
public:
    int search(const ArrayReader& reader, int target) {
        if(reader.get(0) == OUT_OF_BOUND_SIGNAL){
            return -1;
        }
        
        long long left = 0, right = 20000;
        while(left <= right){
            long long mid = ((left + right)>>1);
            if(reader.get(mid) == target){
                return mid;
            } else if(reader.get(mid) < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return -1;
    }
};

//Follow up
// Forward declaration of ArrayReader class.
class ArrayReader;

class Solution {
private:
    const int OUT_OF_BOUND_SIGNAL = INT_MAX;
public:
    int search(const ArrayReader& reader, int target) {
        if(reader.get(0) == OUT_OF_BOUND_SIGNAL){
            return -1;
        }
        
        long long lenthOfArray = findLenthOfArray(reader);
        long long left = 0, right = lenthOfArray;
        while(left <= right){
            long long mid = ((left + right)>>1);
            if(reader.get(mid) == target){
                return mid;
            } else if(reader.get(mid) < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return -1;
    }
    
private:
    long long findLenthOfArray(const ArrayReader& reader){
        long long left = 1, right = INT_MAX;
        long long lenthOfArray = 1;
        while(left <= right){
            long long mid = ((left + right)>>1);
            if(reader.get(mid) == OUT_OF_BOUND_SIGNAL){
                right = mid - 1;
            } else {
                lenthOfArray = mid;
                left = mid + 1;
            }
        }
        
        return lenthOfArray;
    }  
};
