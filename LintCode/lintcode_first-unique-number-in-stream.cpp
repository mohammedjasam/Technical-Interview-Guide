/*
*
* Tag: Data Structure
* Time: O(n)
* Space: O(n)
*/
class Solution {
private:
    const int UNIQUE_NUM_NOT_FOUND_STATE = -1;
public:
    /*
     * @param : a continuous stream of numbers
     * @param : a number
     * @return: returns the first unique number
     */
    int firstUniqueNumber(vector<int> nums, int number) {
        if(nums.size() == 0)
            return UNIQUE_NUM_NOT_FOUND_STATE;
        
        unordered_map<int,int> num_cnt;
        queue<int> num_first_reached_queue;
        
        bool isTerminatingNumberFound = false;
        for(int i = 0; i < nums.size(); ++ i){
            if(reachTerminatingNumber(nums[i], number)){
                isTerminatingNumberFound = true;
                break;
            }
            ++ num_cnt[nums[i]];
            if(isNumReachedInStreamFirstTime(nums[i], num_cnt)) {
                num_first_reached_queue.push(nums[i]);
            }
        }
        
        if(!isTerminatingNumberFound)
            return UNIQUE_NUM_NOT_FOUND_STATE;
        return getUniqueNum(num_cnt, num_first_reached_queue);
    }
private:
    bool reachTerminatingNumber(int cur_num, int terminating_num) {
        return cur_num == terminating_num;
    }
    
    bool isNumReachedInStreamFirstTime(int cur_num, unordered_map<int,int> &num_cnt) {
        return num_cnt[cur_num] == 1;
    }

    int getUniqueNum(unordered_map<int,int> &num_cnt, queue<int> &num_first_reached_queue){
        while(!num_first_reached_queue.empty()) {
            int cur_num = num_first_reached_queue.front();
            num_first_reached_queue.pop();
            if(num_cnt[cur_num] == 1)
                return cur_num;
        }
        return UNIQUE_NUM_NOT_FOUND_STATE;
    }
};
