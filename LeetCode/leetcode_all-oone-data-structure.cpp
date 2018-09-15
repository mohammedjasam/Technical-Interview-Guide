/*
*
* Tag: Data Structure
* Time: O(1)
* Space: O(n)
*/
class AllOne {
public:
    struct Row{
        list<string> strs;
        int val;
        Row(const string &s, int v): strs({s}), val(v) {}
    };
    
    unordered_map<string, pair<list<Row>::iterator,list<string>::iterator> > strmap;
    list<Row> matrix;

    /** Initialize your data structure here. */
    AllOne() {
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if(strmap.find(key) == strmap.end()){
            list<Row>::iterator newrow;
            if (matrix.empty() || matrix.back().val != 1) {
                newrow = matrix.emplace(matrix.end(), key, 1);
                strmap[key] = make_pair(newrow, newrow->strs.begin());
            } else {
                newrow = --matrix.end();
                newrow->strs.push_front(key);
                strmap[key] = make_pair(newrow, newrow->strs.begin());
            }
        }else{
            list<Row>::iterator row = strmap[key].first;
            list<string>::iterator col = strmap[key].second;
            list<Row>::iterator nxtrow = row, newrow;
            -- nxtrow;
            if(nxtrow == matrix.end() || nxtrow->val != row->val + 1){
                newrow = matrix.emplace(row, key, row->val + 1);
                strmap[key] = make_pair(newrow, newrow->strs.begin());
            }else{
                newrow = nxtrow;
                newrow->strs.push_front(key);
                strmap[key] = make_pair(newrow, newrow->strs.begin());
            }
            row->strs.erase(col);
            if(row->strs.empty())
                matrix.erase(row);
        }
        
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if(strmap.find(key) == strmap.end())
            return ;
        else{
            list<Row>::iterator row = strmap[key].first;
            list<string>::iterator col = strmap[key].second;
            if(row->val == 1){
                row->strs.erase(col);
                if(row->strs.empty())
                    matrix.erase(row);
                strmap.erase(key);
                return ;
            }
            list<Row>::iterator nxtrow = row, newrow;
            ++ nxtrow;
            if(nxtrow == matrix.end() || nxtrow->val != row->val - 1){
                newrow = matrix.emplace(nxtrow, key, row->val - 1);
                strmap[key] = make_pair(newrow, newrow->strs.begin());
            }else{
                newrow = nxtrow;
                newrow->strs.push_front(key);
                strmap[key] = make_pair(newrow, newrow->strs.begin());
            }
            row->strs.erase(col);
            if(row->strs.empty())
                matrix.erase(row);
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return matrix.empty()? "" : matrix.front().strs.front();
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return matrix.empty()? "" : matrix.back().strs.front();
    }
};
