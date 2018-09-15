/*
*
* Tag: Heap
* Time: O(nlgk)
* Space: O(n)
*/
class Solution {
private:
    unordered_map<string,int> frequencyOfWord;
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        if(words.size() == 0 || k == 0){
            return ans;
        }
        
        buildFrequencyOfWords( words );
        
        // The less frequent and larger alphabetical order word is at the top.
        priority_queue<pair<string,int>,vector<pair<string,int>>,frequencyOfWordComparator> pq;
        for(auto it : frequencyOfWord){
            pair<string,int> frequencyOfword = make_pair(it.first, it.second);            
            
            if( pq.size() < k ){
                pq.push(frequencyOfword);
            } else {
                pq.push(frequencyOfword);
                pq.pop();
            }            
        }
        
        while(!pq.empty()){
            // Add to the front of vector.
            ans.insert(ans.begin(), pq.top().first);
            pq.pop();
        }
        
        return ans;
    }
private:
    void buildFrequencyOfWords( vector<string>& words ){
        frequencyOfWord.clear();
        
        for(string word : words){
            ++ frequencyOfWord[word];
        }
    }
    
    bool isLessFrequent( pair<string,int> &a, pair<string,int> &b ){
        return a.second < b.second || (a.first > b.first && a.second == b.second);
    }
    
    struct frequencyOfWordComparator {
        bool operator() (const pair<string,int> &a, const pair<string,int> &b){
            return a.second == b.second ? a.first < b.first : b.second < a.second;
        }
    }cmp;
};
