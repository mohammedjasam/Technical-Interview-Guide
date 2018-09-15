/*
*
* Tag: Data Structure
* Time: O(1)
* Space: O(n)
*/
class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        upbnd = maxNumbers - 1;
        used.resize(maxNumbers + 1, false);
        dict.resize(maxNumbers + 1);
         fnt = rear = 0;
        for(int i = 0; i < maxNumbers; ++ i)
            dict[rear ++] = i;
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if(fnt >= rear)
            return -1;
        int res = dict[fnt ++];
        used[res] = true;
        return res;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        if(number < 0 || number > upbnd)
            return false;
        return !used[number];
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if(number >= 0 && number <= upbnd && used[number]){
            used[number] = false;
            dict[-- fnt] = number;
        }
    }
private:
    vector<int> dict;
    vector<bool> used;
    int upbnd, fnt, rear;
};
