/*
*
* Tag: HashMap (Data Structure)
* Time: O(1)
* Space: O(n)
*/
class Logger {
public:
    /** Initialize your data structure here. */
    Logger() {
        logmap.clear();
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if(logmap.find(message) == logmap.end() || timestamp - logmap[message] >= 10){
            logmap[message] = timestamp;
            return true;
        }
        return false;
    }
private:
unordered_map<string,int> logmap;
};
