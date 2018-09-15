/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    string validIPAddress(string IP) {
        if(IP.size() == 0)
            return "Neither";
        string IPv4 = IP + ".", IPv6 = IP + ":";
        if(checkIPv4(IPv4))
            return "IPv4";
        if(checkIPv6(IPv6))
            return "IPv6";
        return "Neither";
    }
    
private:
    bool checkIPv4(string IP){
        string::iterator it = IP.begin(), nxt;
        int cnt = 0, ipval = 0;
        string val = "";
        while(it != IP.end()){
            nxt = find(it, IP.end(), '.');
            val = string(it, nxt);
            ipval = 0;
            if((val.size() > 1 && val[0] == '0') || val.size() == 0)
                return false;
            for(int i = 0; i < val.size(); ++ i){
                if(val[i] < '0' || val[i] > '9')
                    return false;
                ipval = ipval*10 + (val[i] - '0');
                if(ipval > 255)
                    return false;
            }
            it = nxt + 1;
            ++ cnt;
        }
        return cnt == 4;
    }
    
    bool checkIPv6(string IP){
        string::iterator it = IP.begin(), nxt;
        int cnt = 0;
        bool hasleadingzero = false;
        string val = "";
        while(it != IP.end()){
            nxt = find(it, IP.end(), ':');
            val = string(it, nxt);
            cout<<val<<endl;
            if(val.size() > 4 || val.size() == 0)
                return false;
            for(int i = 0; i < val.size(); ++ i){
                if(!((val[i] >= '0' && val[i] <= '9') || (val[i] >= 'a' && val[i] <= 'f') || (val[i] >= 'A' && val[i] <= 'F')))
                    return false;
            }
            it = nxt + 1;
            ++ cnt;
        }
        return cnt == 8;
    }
};
