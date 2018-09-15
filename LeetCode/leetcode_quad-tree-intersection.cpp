/*
*
* Tag: DFS
* Time: O(n)
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
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        if(quadTree1->isLeaf && quadTree1->val) {
            return quadTree1;
        }
        if(quadTree2->isLeaf && quadTree2->val) {
            return quadTree2;
        }
        if(quadTree1->isLeaf && !quadTree1->val) {
            return quadTree2;
        }
        if(quadTree2->isLeaf && !quadTree2->val) {
            return quadTree1;
        }
        
        auto topLeft = intersect(quadTree1->topLeft, quadTree2->topLeft);
        auto topRight = intersect(quadTree1->topRight, quadTree2->topRight);
        auto bottomLeft = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
        auto bottomRight = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
        
        if(topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf && topLeft->val == topRight->val && topLeft->val == bottomLeft->val && topLeft->val == bottomRight->val) {
            return new Node(topLeft->val, true, NULL, NULL, NULL, NULL);
        } else {
            return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
        }
    }
};
