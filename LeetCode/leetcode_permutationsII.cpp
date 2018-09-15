/*
* Algorithm: DFS
* Time complexity: O(len(num)!)
* Memory complexity: O(len(num))
*/
class Solution {
private:
    vector<vector<int> >result; 
    int data[10];
    int sign[10];
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        result.clear();
        sort(num.begin(),num.end());
        memset(sign,0,sizeof(sign));
        int n=num.size();
        dfs(n,0,num);
        return result;
    }
    void dfs(int n,int index,vector<int> &num)
    {
        if(index==n)
        {
            vector<int >t;
            for(int i=0;i<n;++i)t.push_back(num[data[i]]);
            result.push_back(t);
            return;
        }
        for(int i=0;i<n;++i)
        {
            if(sign[i]==0)
            {
                sign[i]=1;
                data[index]=i;
                dfs(n,index+1,num);
                sign[i]=0;
                while(i<n-1&&num[i+1]==num[i])++i;
            }
        }
    }
};
