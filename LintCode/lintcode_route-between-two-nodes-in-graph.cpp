/*
*
* Tag: BFS
* Time: O(n)
* Space: O(n)
*/
/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param graph: A list of Directed graph node
     * @param s: the starting Directed graph node
     * @param t: the terminal Directed graph node
     * @return: a boolean value
     */
    bool hasRoute(vector<DirectedGraphNode*> graph,
                  DirectedGraphNode* s, DirectedGraphNode* t) {
        // write your code here
        bool hasPath = false;
        if(graph.size() == 0)
            return hasPath;
        bool hasStart = false, hasEnd = false;
        for(int i = 0; i < graph.size(); ++ i){
            if(graph[i] == s)
                hasStart = true;
            if(graph[i] == t)
                hasEnd = true;
        }
        if(!hasStart || !hasEnd)
            return hasPath;
        if(s==t)
            return true;
        vector<DirectedGraphNode*> q;
        int front = 0, rear = 0;
        unordered_set<DirectedGraphNode*> st;
        q.push_back(s);
        st.insert(s);
        ++ rear;
        while(front < rear){
            DirectedGraphNode* u = q[front ++];
            if(u == t){
                hasPath = true;
                break;
            }
            for(int i = 0; i < u->neighbors.size(); ++ i){
                DirectedGraphNode* v = u->neighbors[i];
                if(st.find(v) == st.end()){
                    q.push_back(v);
                    ++ rear;
                    st.insert(v);
                }
            }
        }
        return hasPath;
    }
};


