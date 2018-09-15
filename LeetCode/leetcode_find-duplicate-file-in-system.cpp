/*
*
* Tag: Data Structure
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> file_dict;
        vector<vector<string>> ans;
        if(paths.size() == 0)
            return ans;
        int n = paths.size();
        for(int i = 0; i < n; ++ i){
            size_t idx = paths[i].find(' ');
            if(idx != std::string::npos){
                string dir = paths[i].substr(0, idx) + '/';
                while(idx != std::string::npos){
                    size_t cur = idx + 1;
                    idx = paths[i].find('(', cur);
                    string file = dir + paths[i].substr(cur, idx - cur);
                    cur = idx + 1;
                    idx = paths[i].find(')', cur);
                    string content = paths[i].substr(cur, idx - cur);
                    file_dict[content].push_back(file);
                    idx = paths[i].find(' ', cur);
                }
            }
        }
        for(auto it = file_dict.begin(); it != file_dict.end(); ++ it){
            if(it->second.size() > 1){
                ans.push_back(it->second);
            }
        }
        return ans;
    }
};
