/*
*
* Tag: Data Structure
* Time: Add: O(nlgn); TopK: O(n)
* Space: O(n)
*/
class TopK {
private:
    unordered_map<string,int> wordCount;
    map<int, set<string>> countRank;
    int topK;
public:
    /*
    * @param k: An integer
    */
    TopK(int k) {
        topK = k;
        wordCount.clear();
        countRank.clear();
    }

    /*
     * @param word: A string
     * @return: nothing
     */
    void add(string &word) {
        if(topK <= 0)
            return ;
        
        int cnt = wordCount.count(word) == 0? 1 : wordCount[word] + 1;
        wordCount[word] = cnt;
        
        if(cnt > 1)
            countRank[cnt - 1].erase(word);
        countRank[cnt].insert(word);
    }

    /*
     * @return: the current top k frequent words.
     */
    vector<string> topk() {
        vector<string> ans;
        if(topK <= 0)
            return ans;
            
        int cnt = 0;
        for(auto i = countRank.rbegin(); i != countRank.rend(); ++ i){
            for(auto j : i->second) {
                ans.push_back(j);
                ++ cnt;
                if(cnt >= topK)
                    return ans;
            }
        }
        return ans;
    }
};
