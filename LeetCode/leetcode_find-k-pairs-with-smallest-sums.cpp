/*
*
* Tag: Data Structure (Greedy, Heap)
* Time: O(klgn)
* Space: O(n)
*/
class Solution {
private:
struct node{
    int fval, sval;
    int sum;
    bool operator < (const node &a)const{
        return a.sum < sum;
    }
};
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> ans;
        if(!nums1.size() || !nums2.size() || !k) {
            return ans;
        }
        
        priority_queue<node> pq;
        node a;
        for(int i = 0; i < min(nums1.size(), nums2.size()); ++ i){
            a.fval = i, a.sval = i, a.sum = nums1[i]+nums2[i];
            pq.push(a);
        }
        
        int id = 0;
        while(id < k && !pq.empty()){
            node cur = pq.top(), nxt;
            pq.pop();
            
            ans.push_back(make_pair(nums1[cur.fval], nums2[cur.sval]));
            ++ id;
            if(id >= k) {
                break;
            }
            
            if(cur.sval+1 != cur.fval && cur.sval + 1 > cur.fval && cur.sval+1 < nums2.size()){
                nxt.fval = cur.fval, nxt.sval = cur.sval + 1, nxt.sum = nums1[cur.fval] + nums2[cur.sval + 1];
                pq.push(nxt);
            }
            if(cur.fval+1 != cur.sval && cur.fval + 1 > cur.sval && cur.fval+1 < nums1.size()){
                nxt.fval = cur.fval+1, nxt.sval = cur.sval, nxt.sum = nums1[cur.fval+1] + nums2[cur.sval];
                pq.push(nxt);
            }
        }
        
        return ans;
    }
};
