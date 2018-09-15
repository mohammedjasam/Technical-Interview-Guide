/*
*
* Tag: DFS
* Time: ?
* Space: O(n)
*/
class Solution {
public:
    /**
     * @param expression: A string array
     * @return: The Polish notation of this expression
     */
    vector<string> convertToRPN(vector<string> &expression) {
        // write your code here
        vector<string> ans;
        if(!expression.size())
            return ans;
        vector<string> prefix;
        infixToPrefix(expression, prefix);
        int start = 0;
        ExpressionTreeNode *root = buildExpressionTree(prefix, start);
        ExpressionTreeNode dump("x");
        dump.left = root;
        dfs(dump.left, ans);
        return ans;
    }
    
    void dfs(ExpressionTreeNode *root, vector<string> &ans){
        if(!root)
            return ;
        dfs(root->left, ans);
        dfs(root->right, ans);
        ans.push_back(root->symbol);
    }
    
    ExpressionTreeNode* buildExpressionTree(vector<string>& prefix, int& start) {
        if (prefix.empty()) {
            return nullptr;
        }
        ExpressionTreeNode *node = new ExpressionTreeNode(prefix[start++]);
        if (is_operator(prefix[start - 1])) {
            node->left = buildExpressionTree(prefix, start);
            node->right = buildExpressionTree(prefix, start);
        }
        return node;
    }
    
    bool is_operator(const string &op) {
        return op.length() == 1 && string("+-*/").find(op) != string::npos;
    }
    
    void infixToPrefix(vector<string>& infix, vector<string>& prefix) {
        reverse(infix.begin(), infix.end());
        stack<string> s;
        for (auto tok : infix) {
            if (atoi(tok.c_str())) {
                prefix.push_back(tok);
            } else if (tok == ")") {
                s.push(tok);
            } else if (tok == "(") {
                while (!s.empty()) {
                    tok = s.top();
                    s.pop();
                    if (tok == ")") {
                        break;
                    }
                    prefix.push_back(tok);
                }
            } else {
                while (!s.empty() && precedence(tok) < precedence(s.top())) {
                    prefix.push_back(s.top());
                    s.pop();
                }
                s.push(tok);
            }
        }
        while (!s.empty()) {
            prefix.push_back(s.top());
            s.pop();
        }
        reverse(prefix.begin(), prefix.end());
    }
    
    int precedence(string x) {
        if(x == ")") {
            return 0;
        } else if (x == "+" || x == "-") {
            return 1;
        } else if (x == "*" || x == "/") {
            return 2;
        }
        return 3;
    }
};
