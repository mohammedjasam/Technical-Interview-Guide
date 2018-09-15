/*
*
* Tag: Geometry
* Time: O(1)
* Space: O(1)
*/
class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        if(p1.size() != 2 || p2.size() != 2 || p3.size() != 2 || p4.size() != 2)
            return false;
        if(equalPoint(p1, p2) || equalPoint(p1, p3) || equalPoint(p1, p4) || 
           equalPoint(p2, p3) || equalPoint(p2, p4) || equalPoint(p3, p4))
            return false;
        if(dis(p1, p2) == dis(p3, p4) && sameMidPoint(p1, p2, p3, p4) && dis(p1, p3) == dis(p1, p4) )
            return true;
        if(dis(p1, p3) == dis(p2, p4) && sameMidPoint(p1, p3, p2, p4) && dis(p1, p2) == dis(p1, p4) )
            return true;
        if(dis(p1, p4) == dis(p2, p3) && sameMidPoint(p1, p4, p2, p3) && dis(p1, p2) == dis(p1, p3) )
            return true;
        return false;
    }
    
private:
    inline int dis(vector<int> &p, vector<int> &q){
        return (p[0] - q[0])*(p[0] - q[0]) + (p[1] - q[1])*(p[1] - q[1]);
    }
    
    inline bool sameMidPoint(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4){
        return (p1[0] + p2[0] == p3[0] + p4[0] && p1[1] + p2[1] == p3[1] + p4[1]);
    }
    
    inline bool equalPoint(vector<int> &p, vector<int> &q){
        return p[0] == q[0] && p[1] == q[1];
    }
};

/*
*
* Tag: Geometry && Data Structure
* Time: O(1)
* Space: O(1)
*/
class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        if(p1.size() != 2 || p2.size() != 2 || p3.size() != 2 || p4.size() != 2)
            return false;
        unordered_set<int> s({dis(p1, p2), dis(p1, p3), dis(p1, p4), dis(p2, p3), dis(p2, p4), dis(p3, p4)});
        return !s.count(0) && s.size() == 2;
    }
    
private:
    inline int dis(vector<int> &p, vector<int> &q){
        return (p[0] - q[0])*(p[0] - q[0]) + (p[1] - q[1])*(p[1] - q[1]);
    }
    
};
