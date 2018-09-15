/*
*
* Tag: Fenwick Tree
* Time: O(1)
* Space: O(1)
*/
class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {
        cur_arr.resize(301);
        prev_arr.resize(301);
        bnd = 300;
        previd = 0;
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        int curid = timestamp%300;
        if(!curid)
            curid = 300;
        if(curid < previd || (curid == previd && prestmp < timestamp) || timestamp - prestmp > 300)
            flusharr(timestamp - prestmp > 300);
        updatetime(curid, timestamp);
        update(curid);
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        int cursum = 0, prevsum = 0;
        int curid = timestamp%300;
        if(!curid)
            curid = 300;
        if(curid < previd || (curid == previd && prestmp < timestamp) || timestamp - prestmp > 300)
            flusharr(timestamp - prestmp > 300);
        cursum += sumup(prev_arr, 300);
        cursum += sumup(cur_arr, curid);
        prevsum += sumup(prev_arr, curid);
        updatetime(curid, timestamp);
        return cursum-prevsum;
    }
private:
    int lowbit(int x){
        return x&-x;
    }

    void update(int sta){
        for(int i = sta; i <= bnd; i += lowbit(i)){
            ++ cur_arr[i];
        }
    }
    
    void updatetime(int curid, int timestamp){
        previd = curid;
        prestmp = timestamp;
    }
    
    int sumup(vector<int> &arr, int sta){
        int res = 0;
        for(int i = sta; i > 0; i -= lowbit(i))
            res += arr[i];
        return res;
    }
    
    void flusharr(bool op){
        for(int i = 0; i <= bnd; ++ i){
            prev_arr[i] = cur_arr[i];
            cur_arr[i] = 0;
            if(op)
                prev_arr[i] = 0;
        }
    }
    
    
private:
    vector<int> cur_arr, prev_arr;
    int prestmp, bnd, previd;
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */
