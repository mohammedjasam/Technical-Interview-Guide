/*
*
* Tag: String
* Time: O(n)
* Space: O(1)
*/
class Solution {
private:
    const string noSolution = "No solution";
    const string infiniteSolution = "Infinite solutions";
public:
    string solveEquation(string equation) {
        if(equation.size() == 0){
            return noSolution;
        }
        
        int positionOfEqualSign = equation.find('=');
        string leftFunction = equation.substr(0, positionOfEqualSign);
        string rightFunction = equation.substr(positionOfEqualSign + 1);
        
        pair<int,int> coefficientsOfLeftFunction = getCoefficientFor( leftFunction );
        pair<int,int> coefficientsOfRightFunction = getCoefficientFor( rightFunction );
        
        int coefficientOfX = coefficientsOfLeftFunction.first - coefficientsOfRightFunction.first;
        int constantCoefficient = coefficientsOfRightFunction.second - coefficientsOfLeftFunction.second;
        if(coefficientOfX == 0 && constantCoefficient == 0) {
            return infiniteSolution;
        } else if(coefficientOfX != 0) {
            string valueOfX = to_string( constantCoefficient/coefficientOfX );
            string ans = "x=";
            ans.append(valueOfX);
            return ans;
        }
        
        return noSolution;
    }
    
private:
    pair<int,int> getCoefficientFor(string function){
        int coefficientOfX = 0;
        int constantCoefficient = 0;
        
        for(int i = 0; i < function.size(); ++ i){
            bool isCoefficientOfX = false;
            int coefficient = 0;
            bool isNegative = false;
            
            if(function[i] == '-' || function[i] == '+'){
                isNegative = function[i] == '-';
                ++ i;
            }
            
            if(function[i] == 'x'){
                isCoefficientOfX = true;
                coefficient = 1;
            }
            
            while(i < function.size() && function[i] >= '0' && function[i] <= '9') {
                coefficient = coefficient*10 + (function[i] - '0');
                ++ i;
            }
            
            if(i < function.size() && function[i] == 'x'){
                isCoefficientOfX = true;
            }
            
            if(isCoefficientOfX){
                coefficientOfX += (isNegative ? -coefficient : coefficient);
            } else {
                constantCoefficient += (isNegative ? -coefficient : coefficient);
            }
            
            if(i < function.size() && function[i] == '+' || function[i] == '-'){
                -- i;
            }
        }
        
        return make_pair(coefficientOfX, constantCoefficient);
    }
};
