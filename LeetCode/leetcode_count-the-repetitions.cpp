/*
*
* Tag: 
* Time: O(len(s1)*len(s2))
* Space: O(max(len(s1),len(s2)))
*/
class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        vector<int> rapport(102,-1);
        vector<int> rest(102,-1);
        int b=-1, posRest=0, rap=0, last=-1;
        rapport[0]=rest[0]=0;
        for(int i=1;i<=s2.size()+1;i++){
            for(int j=0;j<s1.size();j++){
                if(s2[posRest]==s1[j]){
                    posRest++;
                    if(posRest==s2.size()){
                        rap++;
                        posRest=0;
                    }
                }
            }
            for(int k=0;k<i;k++){
                if(posRest==rest[k]){b=k;last=i;break;}
            }
            rapport[i]=rap;rest[i]=posRest;
            if(b>=0)break;
        }
        int interval=last-b;
        if(b>=n1)
            return rapport[n1];
        return ((n1-b)/interval*(rapport[last]-rapport[b])+rapport[(n1-b)%interval+b])/n2;
    }
};
