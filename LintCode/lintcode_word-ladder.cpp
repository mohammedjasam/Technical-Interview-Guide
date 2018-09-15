/*
*
* Tag: BFS
* Time: O(26^n) (n is the length of string)
* Space: O(26^n)
*/
class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return an integer
      */
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // write your code here
        if(start == end)
            return 0;
        vector<string> q;
        int front = 0, rear = 0, lv_rear = 0;
        q.push_back(start);
        rear = lv_rear = 1;
        int len = 0;
        while(front < rear && dict.size() > 0){
            ++ len;
            while(front < rear && dict.size() > 0){
                string u = q[front ++];
                for(int i = 0; i < u.size(); ++ i){
                    for(int j = 0; j < 26; ++ j){
                        char ch = (j + 'a');
                        if(ch == u[i])
                            continue;
                        string v = u;
                        v[i] = ch;
                        if(dict.find(v) != dict.end()){
                            q.push_back(v);
                            ++ lv_rear;
                            dict.erase(v);
                            if(v == end){
                                return len + 1;
                            }
                            if(dict.size() <= 0)
                                break;
                        }
                    }
                    if(dict.size() <= 0)
                        break;
                }
            }
            front = rear;
            rear = lv_rear;
        }
        return 0;
    }
};
