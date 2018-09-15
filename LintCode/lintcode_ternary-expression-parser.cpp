/*
*
* Tag: DFS
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    /**
     * @param expression: a string, denote the ternary expression
     * @return: a string
     */
    string parseTernary(string expression) {
        int n = expression.size();
        if(n <= 1)
            return expression;
        
        string op = "", valFirst = "", valSecond = "";
        if(expression[3] == ':'){
            op += expression[0];
            valFirst += expression[2];
            valSecond += expression.substr(4);
            return parseTernary(calculateEvaluation(op, valFirst, parseTernary(valSecond)));
        } else {
            op += expression[0];
            valFirst += expression.substr(2, n - 4);
            valSecond += expression[n - 1];
            return parseTernary(calculateEvaluation(op, parseTernary(valFirst), valSecond));
        }
    }
    
private:
    string calculateEvaluation(string op, string valFirst, string valSecond) {
        return op == "T"? valFirst : valSecond;
    }
};
