/*
*
* Tag: Brute Force
* Time: O(n)
* Space: O(1)
*/
class Solution {
private:
    const int TOTAL_MINS_A_DAY = 1440;
public:
    string nextClosestTime(string time) {
        if(time.size() == 0){
            return time;
        }
        
        vector<bool> digitPresenceOfTime = getDigitPresenceOfTime( time );
        
        string ans = "";
        string currentTime = time;
        for(int i = 0; i < TOTAL_MINS_A_DAY; ++ i){
            string nextTime = getTimeAfterOneMinute( currentTime );
            
            if(canTimeConsistOf( nextTime, digitPresenceOfTime )){
                ans = nextTime;
                break;
            }
            
            currentTime = nextTime;
        }
        
        return ans;
    }
private:
    vector<bool> getDigitPresenceOfTime( string time ) {
        vector<bool> presentDigit(10, false);
        for(char letter : time){
            if(isdigit(letter)){
                presentDigit[(letter - '0')] = true;
            }
        }
        
        return presentDigit;
    }
    
    string getTimeAfterOneMinute( string currentTime ) {        
        int hour = stoi(currentTime.substr(0, 2));
        int minute = stoi(currentTime.substr(3));
        
        int nextMinute = (minute + 1)%60;
        int nextHour = nextMinute == 0 ? (hour + 1)%24 : hour;
        
        string nextHourString = (nextHour < 10 ? "0" : "") + to_string(nextHour);
        string nextMinuteString = (nextMinute < 10 ? "0" : "") + to_string(nextMinute);
        string nextTime = nextHourString + ":" + nextMinuteString;        
        return nextTime;
    }
    
    bool canTimeConsistOf( string time, vector<bool> &digitPresenceOfTime ){
        for(char letter : time){
            if(isdigit(letter)){
                int digit = (letter - '0');
                if(!digitPresenceOfTime[digit]){
                    return false;
                }
            }
        }
        
        return true;
    }
};
