/*
*
* Tag: String
* Time: O(n)
* Space: O(n)
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

class CSVParser {
public:
    string parseCSV(string text){
        string ans = "";
        if(text.size() == 0){
            return ans;
        }
        
        bool isQuoted = false;
        vector<string> csvColumns;
        string csvColumn = "";
        for(int i = 0; i < text.size(); ++ i){
            if(isQuoted) {
                if(text[i] == '\"') {
                    if(i < text.size() - 1 && text[i + 1] == '\"') {
                        csvColumn += "\"";
                        ++ i;
                    } else {
                        isQuoted = false;
                    }
                } else {
                    csvColumn += text[i];
                }
                
            } else {
                if(text[i] == '\"'){
                    isQuoted = true;
                } else if(text[i] == ',') {
                    csvColumns.push_back(csvColumn);
                    csvColumn = "";
                } else {
                    csvColumn += text[i];
                }
            }
        }
        if(csvColumn.size() > 0){
            csvColumns.push_back(csvColumn);
        }
        
        for(int i = 0; i < csvColumns.size(); ++ i){
            if(i > 0){
                ans += '|';
            }
            
            ans += csvColumns[i];
        }
        return ans;
    }
};

int main() {
    CSVParser cp;
    string text1= "John,Smith,john.smith@gmail.com,Los Angeles,1";
    string ans1 = cp.parseCSV(text1);
    cout<<ans1<<endl;
    
    string text2= "\"Alexandra \"\"Alex\"\"\",Menendez,alex.menendez@gmail.com,Miami,1";
    string ans2 = cp.parseCSV(text2);
    cout<<ans2<<endl;
    
    string text3= "\"\"\"Alexandra Alex\"\"\"";
    string ans3 = cp.parseCSV(text3);
    cout<<ans3<<endl;
    
    string text4= "\"Alexandra \"\"Alex\"\"\",Menendez,alex.menendez@gmail.com,Miami,1\"";
    string ans4 = cp.parseCSV(text4);
    cout<<ans4<<endl;
    
    string text5= "\"Alexandra \"\"Alex\"\"\",Menendez,alex.menendez@gmail.com,Miami,\"1";
    string ans5 = cp.parseCSV(text5);
    cout<<ans5<<endl;
    return 0;
}
