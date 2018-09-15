/*
*
* Tag: Sort
* Time: O(nlgn)
* Space: O(lgn)
*/
class Solution {
public:
    /**
     *@param num: A list of non negative integers
     *@return: A string
     */
    string largestNumber(vector<int> &num) {
        // write your code here
        string ans = "";
        if(num.size() == 0)
            return ans;
        vector<string> arr(num.size());
        for(int i = 0; i < num.size(); ++ i){
            stringstream ss;
            ss << num[i];
            string str = ss.str();
            arr[i] = str;
        }
        sort(arr.begin(), arr.end(), mycmp);
        for(int i = 0; i < arr.size(); ++ i)
            ans += arr[i];
        if(arr[0] == "0")
            ans = "0";
        return ans;
    }

private:
    struct cmp{
        bool operator() (const string &a, const string &b){
            return (b+a) < (a+b);
        }
    }mycmp;
};
