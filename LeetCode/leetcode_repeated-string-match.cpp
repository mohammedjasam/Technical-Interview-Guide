/*
*
* Tag:
* Time:
* Space:
*/
class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        if(A == B || A.find(B) < A.size()){
            return 1;
        }
        
        string repeatedTwoAs = A+A;
        if(repeatedTwoAs.find(B) < repeatedTwoAs.size()){
            return 2;
        }
        
        int lenOfSuffixOfAasPrefixOfB = B.find(A);
        if(lenOfSuffixOfAasPrefixOfB > B.size()){
            return -1;
        }
        
        if(lenOfSuffixOfAasPrefixOfB > 0){
            string prefixB = B.substr(0, lenOfSuffixOfAasPrefixOfB);
            if(A.find(prefixB) > A.size()){
                return -1;
            }
        }
        
        string newB = lenOfSuffixOfAasPrefixOfB > 0 ? B.substr(lenOfSuffixOfAasPrefixOfB) : B;
        int ans = 0;
        for(int i = 0; i < newB.size(); i += A.size()){
            if(newB.find(A, i) > newB.size()){
                
                string suffix = newB.substr(i);
                if(A.find(suffix) != 0){
                    return -1;
                }
                
            }
            ++ ans;
        }
        
        return lenOfSuffixOfAasPrefixOfB > 0 ? ans + 1: ans;
    }
};
