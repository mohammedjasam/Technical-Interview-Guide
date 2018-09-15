/*
*
* Tag: Divide and Conquer
* Time: O(n^2)
* Space: O(n)
*/
class Solution {
public:
    enum {start, end, height};
    /**
     * @param buildings: A list of lists of integers
     * @return: Find the outline of those buildings
     */
    vector<vector<int> > buildingOutline(vector<vector<int> > &buildings) {
        return calBuildOutline(buildings, 0, buildings.size());
    }
    
    vector<vector<int> > calBuildOutline(vector<vector<int> >& buildings, int l, int r){
        if(r - l <= 1){
            return {buildings.cbegin() + l, buildings.cbegin() + r};
        }
        int mid = l + ((r - l)>>1);
        vector<vector<int> > l_b = calBuildOutline(buildings, l, mid);
        vector<vector<int> > r_b = calBuildOutline(buildings, mid, r);
        return mergeOutline(l_b, r_b);
    }
    
    vector<vector<int>> mergeOutline(vector<vector<int>>& l_b, vector<vector<int>>& r_b){
        int i = 0, j = 0;
        vector<vector<int>> merged;
        
        while(i < l_b.size() && j < r_b.size()){
            if(l_b[i][end] < r_b[j][start]){
                merged.emplace_back(l_b[i ++ ]);
                
            }else if(r_b[j][end] < l_b[i][start]){
                merged.emplace_back(r_b[j ++ ]);
                
            }else if(l_b[i][start] <= r_b[j][start]){
                mergeInterOutline(merged, l_b[i], i, r_b[j], j);
                
            }else{
                mergeInterOutline(merged, r_b[j], j, l_b[i], i);
                
            }
        }
        
        merged.insert(merged.end(), l_b.begin() + i, l_b.end());
        merged.insert(merged.end(), r_b.begin() + j, r_b.end());
        return merged;
    }
    
    void mergeInterOutline(vector<vector<int>>& merged, vector<int>& a, int& a_idx,
                                vector<int>& b, int& b_idx){
        if(a[end] <= b[end]){
            if(a[height] > b[height]){
                if(b[end] != a[end]) {
                    merged.emplace_back(a), ++a_idx;
                    b[start] = a[end];
                }else{
                    ++b_idx;
                }
            }else if(a[height] == b[height]){
                b[start] = a[start];
                ++ a_idx;
            }else{
                if(a[start] != b[start]) { 
                    merged.emplace_back(vector<int>{a[start], b[start], a[height]});
                }
                ++a_idx;
            }
        }else{
            if(a[height] >= b[height]){
                ++ b_idx;
            }else{
                if(a[start] != b[start]){
                    merged.emplace_back(vector<int>{a[start], b[start], a[height]});
                }
                a[start] = b[end];
                merged.emplace_back(b), ++b_idx;
            }
        }                            
    }
    
};
