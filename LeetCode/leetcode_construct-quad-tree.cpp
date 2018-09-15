/*
*
* Tag: DFS
* Time: O(n^2)
* Space: O(n)
*/
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
private:
    vector<vector<int>> sum;
public:
    Node* construct(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0){
            return NULL;
        }
        
        init(grid);
        return buildQuadTree(make_pair(0, 0), make_pair(grid.size() - 1, grid[0].size() - 1));
    }
    
private:
    void init(vector<vector<int>>& grid){
        int numOfRows = grid.size(), numOfColumns = grid[0].size();
        sum.resize(numOfRows);
        
        for(int i = 0; i < numOfRows; ++ i){
            vector<int> columns(numOfColumns, 0);
            sum[i] = columns;
        }
        
        for(int i = 0; i < numOfRows; ++ i){
            for(int j = 0; j < numOfColumns; ++ j){
                sum[i][j] += grid[i][j];
                if(i > 0){
                    sum[i][j] += sum[i - 1][j];
                }
                if(j > 0){
                    sum[i][j] += sum[i][j - 1];
                }
                if(i > 0 && j > 0){
                    sum[i][j] -= sum[i - 1][j - 1];
                }
            }
        }
    }
    
    Node* buildQuadTree(pair<int,int> topLeftPoint, pair<int,int> bottomRightPoint){
        Node *root = NULL;
        int quadSize = bottomRightPoint.first - topLeftPoint.first + 1;
        int quadSum = getQuadSum(topLeftPoint, bottomRightPoint);
        if(quadSum == 0 || quadSum == quadSize*quadSize || quadSize <= 1){
            root = new Node(quadSum != 0, true, NULL, NULL, NULL, NULL);
            return root;
        }
        
        root = new Node(quadSum != 0, false, NULL, NULL, NULL, NULL);
        root->topLeft = buildQuadTree(topLeftPoint, make_pair(topLeftPoint.first + quadSize/2 - 1, topLeftPoint.second + quadSize/2 - 1 ));
        
        root->topRight = buildQuadTree(make_pair(topLeftPoint.first, topLeftPoint.second + quadSize/2), make_pair(topLeftPoint.first + quadSize/2 - 1, bottomRightPoint.second ));
        
        root->bottomLeft = buildQuadTree(make_pair(topLeftPoint.first + quadSize/2, topLeftPoint.second), make_pair(bottomRightPoint.first, topLeftPoint.second + quadSize/2 - 1 ));
        
        root->bottomRight = buildQuadTree(make_pair(topLeftPoint.first + quadSize/2, topLeftPoint.second + quadSize/2), bottomRightPoint );
        
        return root;
    }
    
    int getQuadSum(pair<int,int> topLeftPoint, pair<int,int> bottomRightPoint){
        int quadSum = sum[bottomRightPoint.first][bottomRightPoint.second];
        if(topLeftPoint.first > 0){
            quadSum -= sum[topLeftPoint.first - 1][bottomRightPoint.second];
        }
        if(topLeftPoint.second > 0){
            quadSum -= sum[bottomRightPoint.first][topLeftPoint.second - 1];
        }
        if(topLeftPoint.first > 0 && topLeftPoint.second > 0){
            quadSum += sum[topLeftPoint.first - 1][topLeftPoint.second - 1];
        }
        
        return quadSum;
    }
};
