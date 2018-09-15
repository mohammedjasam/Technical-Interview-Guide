/*
*
* Tag: Data Structure
* Time: O(1)
* Space: O(n)
*/
class LFUCache {
private:
    struct Row{
        list<pair<int,int>> cols;
        int freq;
        Row(int k, int v, int f){
            cols.push_back(make_pair(k, v));
            freq = f;
        }
    };
    
    unordered_map<int, pair<list<Row>::iterator,list<pair<int,int>>::iterator> > dict;
    list<Row> cache;
    int cap, curcap;
public:
    LFUCache(int capacity) {
        dict.clear();
        cache.clear();
        cap = capacity;
        curcap = 0;
    }
    
    int get(int key) {
        if(dict.find(key) == dict.end())
            return -1;
        int value = 0;
        value = dict[key].second->second;
        updateCache(key, value);
        return value;
    }
    
    void set(int key, int value) {
        if(!cap)
            return ;
        if(dict.find(key) == dict.end()){
            list<Row>::iterator row, newrow, nxtrow;
            list<pair<int,int>>::iterator col;
            if(curcap >= cap){
                row = cache.end();
                -- row;
                col = row->cols.end();
                -- col;
                row->cols.pop_back();
                if(row->cols.empty())
                    cache.erase(row);
                dict.erase(col->first);
                -- curcap;
            }
            if(cache.empty() || cache.back().freq != 1){
                newrow = cache.emplace(cache.end(), key, value, 1);
            }else{
                newrow = --cache.end();
                newrow->cols.push_front(make_pair(key, value));
            }
            dict[key] = make_pair(newrow, newrow->cols.begin());
            ++ curcap;
        }else{
            updateCache(key, value);
        }
    }

private:
    void updateCache(int key, int value){
        list<Row>::iterator row = dict[key].first, nxtrow, newrow;
        list<pair<int,int>>::iterator col = dict[key].second;
        nxtrow = row;
        -- nxtrow;
        if(nxtrow == cache.end() || nxtrow->freq != row->freq + 1){
            newrow = cache.emplace(row, key, value, row->freq + 1);
        }else{
            newrow = nxtrow;
            newrow->cols.push_front(make_pair(key, value));
        }
        dict[key] = make_pair(newrow, newrow->cols.begin());
        row->cols.erase(col);
        if(row->cols.empty())
            cache.erase(row);
    }
};
