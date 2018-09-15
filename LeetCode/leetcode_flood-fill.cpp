/*
*
* Tag: DFS
* Time: O(nm) n is number of rows and m is the number of columns of image.
* Space: O(nm)
*/
class Solution {
private:
    int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<int>> newImage(image.begin(), image.end());
        if(image.size() == 0 || (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size())){
            return newImage;
        }
        
        int oldColor = image[sr][sc];
        if(newColor == oldColor){
            return newImage;
        }
        
        dfs(newImage, sr, sc, oldColor, newColor);
        
        return newImage;
    }
private:
    void dfs(vector<vector<int>>& image, int sr, int sc, int oldColor, int newColor){
        image[sr][sc] = newColor;
        
        for(int i = 0; i < 4; ++ i){
            int nextSr = sr + dir[i][0], nextSc = sc + dir[i][1];
            if(nextSr >= 0 && nextSr < image.size() && nextSc >= 0 && nextSc < image[0].size() && image[nextSr][nextSc] == oldColor){
                dfs(image, nextSr, nextSc, oldColor, newColor);
            }
        }
    }
};
