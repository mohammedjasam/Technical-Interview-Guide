/*
*
* Tag: Bit Manipulation
* Time: O(n*2^n)
* Space: O(2^n)
*/

#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <ctype.h>
using namespace std;

class caseCombinator {
public:
  vector<string> findAllCaseCombinations(string text){
    vector<string> ans;
    if(text.size() == 0){
      return ans;
    }
    
    int n = text.size();
    int totalSize = 1<<n;
    ans.resize(totalSize);
    for(int i = 0; i < totalSize; ++ i){
      string curCombination = text;
      for(int j = 0; j < n; ++ j){
        curCombination[j] = isBitSet(j, i) ? toupper(text[j]) : tolower(text[j]);
      }
      
      ans[i] = curCombination;
    }
    
    return ans;
  }
  
private:
  bool isBitSet(int pos, int val){
    return (val>>pos & 1) != 0;
  }
};

int main() {
  caseCombinator cc;
  string text1 = "";
  vector<string> ans1 = cc.findAllCaseCombinations(text1);
  for(string ans : ans1){
    cout<<ans<<endl;
  }
  cout<<endl;
  
  string text2 = "abc";
  vector<string> ans2 = cc.findAllCaseCombinations(text2);
  for(string ans : ans2){
    cout<<ans<<endl;
  }
  cout<<endl;
  
  string text3 = "abCdE";
  vector<string> ans3 = cc.findAllCaseCombinations(text3);
  for(string ans : ans3){
    cout<<ans<<endl;
  }
  cout<<endl;
  return 0;
}
