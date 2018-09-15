/*
*
* Tag: Bit Manipulation
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    vector<string> ipToCIDR(string ip, int n) {
        vector<string> ans;
        if(n == 0){
            return ans;
        }
        
        istringstream is(ip);
        long x = 0;
        string address;
        while(getline(is, address, '.')){
            x = x*256 + stoi(address);
        }
                
        while(n > 0){
            long step = x & -x;
            while(step > n){
                step >>= 1;
            }
            
            ans.push_back( intToIp(x, step) );
            x += step;
            n -= step;
        }
        
        return ans;
    }

private:
    string intToIp(long x, long step){
        vector<int> addresses(4);       
        for(int i = 3; i >= 0; -- i){
            addresses[i] = x&255;
            x >>= 8;
        }
        
        string ip = "";
        for(int i = 0; i < 4; ++ i){
            if(i > 0){
                ip += ".";
            }
            
            ip += to_string(addresses[i]);
        }
        
        ip += "/";
        ip += to_string( 32 - (int)log2(step) );
        
        return ip;
    }
};
