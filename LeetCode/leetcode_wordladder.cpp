/*
* Algorithm: BFS
* Time complexity: O(?)
* Memory complexity: O(?)
*/
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if(start.size() != end.size())
            return 0;
        if(start.empty() || end.empty())
            return 1;
        if(dict.size() == 0)
            return 0;
        int dist = 1;
        queue<string> queTopush, queTopop;
        queTopop.push(start);
        while(dict.size() > 0 && !queTopop.empty()){
            while(!queTopop.empty()){
                string str = queTopop.front();
                queTopop.pop();
                for(int i = 0; i < str.size(); i ++){
                    for(int j = 'a'; j <= 'z'; j ++){
                        if(j == str[i])
                            continue;
                        char tmp = str[i];
                        str[i] = j;
                        if(str == end)
                            return dist + 1;
                        if(dict.find(str) != dict.end()){
                            queTopush.push(str);
                            dict.erase(str);
                        }
                        str[i] = tmp;
                    }
                }
            }
            swap(queTopush, queTopop);
            dist ++;
        }
        return 0;
    }
};
