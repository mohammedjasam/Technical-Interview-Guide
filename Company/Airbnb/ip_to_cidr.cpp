/*
*
* Tag: Bit Manipulation
* Time: O(lgn)
* Space: O(1)
*/
#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <cmath>
#include <ctype.h>
#include <climits>
#include <utility>
using namespace std;

class IPConverter {
public:
    vector<string> ipToCIDR(string ip, int n) {
        vector<string> ans;
        if(n == 0){
            return ans;
        }
        
        istringstream is(ip);
        long ipCode = 0;
        string address;
        while(getline(is, address, '.')){
            ipCode = ipCode*256 + stoi(address);
        }
        
        while(n > 0){
            long step = ipCode & -ipCode;
            
            if(step == 0){
                step = 1L<<32;
            }
            
            while(step > n){
                step >>= 1;
            }
            
            ans.push_back(convertIpCodeToString(ipCode, step));
            ipCode += step;
            n -= step;
        }
        
        return ans;
    }

private:
    string convertIpCodeToString(long ipCode, long step){
        vector<long> addresses(4);
        for(int i = 3; i >= 0; -- i){
            addresses[i] = ipCode&255;
            ipCode >>= 8;
        }
        
        string ip = "";
        for(int i = 0; i < 4; ++ i){
            if(i > 0){
                ip += '.';
            }
            
            ip += to_string(addresses[i]);
        }
        
        ip += '/';
        ip += to_string( 32 - (int)log2(step) );
        
        return ip;
    }
};

int main() {
    IPConverter ic;
    string ip = "255.0.0.7";
    int n = 10;
    vector<string> ips = ic.ipToCIDR(ip, n);
    for(string ans : ips){
        cout<<ans<<endl;
    }
    cout<<endl;
    
    return 0;
}
