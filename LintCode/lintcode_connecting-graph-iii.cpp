/*
*
* Tag: Data Structure (Union Find)
* Time: O(n)
* Space: O(n)
*/
class ConnectingGraph3 {
private:
    int numOfConnectedComponents;
    vector<int> parentOfNode;
public:
    /*
    * @param n: An integer
    */
    ConnectingGraph3(int n) {
        numOfConnectedComponents = n;
        parentOfNode.resize(n + 1);
        
        for(int i = 0; i <= n; ++ i)
            parentOfNode[i] = -1;
    }

    /*
     * @param a: An integer
     * @param b: An integer
     * @return: nothing
     */
    void connect(int a, int b) {
        int parentOfNodeA = findParent(a), parentOfNodeB = findParent(b);
        
        if(parentOfNodeA == parentOfNodeB)
            return ;
        
        -- numOfConnectedComponents;
        
        int connectedParent = parentOfNode[parentOfNodeA] + parentOfNode[parentOfNodeB];
        if(parentOfNode[parentOfNodeA] > parentOfNode[parentOfNodeB]) {
            parentOfNode[parentOfNodeA] = parentOfNodeB;
            parentOfNode[parentOfNodeB] = connectedParent;
        } else {
            parentOfNode[parentOfNodeB] = parentOfNodeA;
            parentOfNode[parentOfNodeA] = connectedParent;
        }
    }

    /*
     * @return: An integer
     */
    int query() {
        return numOfConnectedComponents;
    }
    
private:
    int findParent(int node){
        int curNode = node;
        for(curNode = node; parentOfNode[curNode] >= 0; curNode = parentOfNode[curNode]) ;
        
        while(curNode != node) {
            int curParent = parentOfNode[node];
            parentOfNode[node] = curNode;
            node = curParent;
        }
        
        return curNode;
    }
};
