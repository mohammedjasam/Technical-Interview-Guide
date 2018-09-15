/*
*
* Tag: Brute Force
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:    
    /**
     * @param source: A string
     * @param target: A string
     * @return: A string denote the minimum window
     *          Return "" if there is no such a string
     */
    string minWindow(string &source, string &target) {
        // write your code here
        if(source.size() == 0 || source.size() < target.size())
            return "";
        vector<int> expect(260), appear(260);
        for(int i = 0; i < target.size(); ++ i)
            expect[target[i]] ++;
        int l = 0, r, num = 0, ans = INT_MAX, anssta = 0;
        for(int i = 0; i < source.size(); ++ i){
            if(expect[source[i]] > 0){
                appear[source[i]] ++;
                if(appear[source[i]] <= expect[source[i]])
                    num ++;
            }
            if(num == target.size()){
                r = i;
                while(appear[source[l]] > expect[source[l]] || expect[source[l]] == 0){
                    appear[source[l]] --;
                    l ++;
                }
                if(ans > r - l + 1){
                    ans = r - l + 1;
                    anssta = l; 
                }
            }
        }
        
        if(ans == INT_MAX)
            return "";
        else
            return source.substr(anssta, ans);
    }
};

