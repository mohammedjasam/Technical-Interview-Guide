/*
*
* Tag: Geometry
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    bool isConvex(vector<vector<int>>& p) {
      long n = p.size(), prev = 0, cur;
      for (int i = 0; i < n; ++i) {
        vector<vector<int>> A; // = {p[(i+1)%n]-p[i], p[(i+2)%n]-p[i]}
        for (int j = 1; j < 3; ++j) A.push_back({p[(i+j)%n][0]-p[i][0], p[(i+j)%n][1]-p[i][1]});
        if (cur = det2(A)) if (cur*prev < 0) return false; else prev = cur;
      }
      return true;
    }
    
    long det2(vector<vector<int>>& A) { return A[0][0]*A[1][1] - A[0][1]*A[1][0]; }
};
