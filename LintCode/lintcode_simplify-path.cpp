/*
*
* Tag: String
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param path the original path
     * @return the simplified path
     */
    string simplifyPath(string& path) {
        // Write your code here
        vector<string> dirs;
        
        for(auto i = path.begin(); i != path.end(); ){
            i ++;
            
            auto j = find(i,path.end(),'/');
            auto dir = string(i, j);
            
            if(!dir.empty() && dir != "."){
                if(dir == ".."){
                    if(!dirs.empty())
                        dirs.pop_back();
                }else{
                    dirs.push_back(dir);
                }
            }
            
            i = j;
        }
        
        stringstream out;
        if(dirs.empty()){
            out<<"/";
        }else{
            for(auto dir : dirs)
                out<<'/'<<dir;
        }
        return out.str();
    }
};
