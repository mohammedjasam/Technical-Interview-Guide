/*
*
* Tag: DFS
* Time: O(26^n)
* Space: O(26^n)
*/
class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return a list of lists of string
      */
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // write your code here
        unordered_set<string> current, next; 
        unordered_set<string> visited;
        unordered_map<string, vector<string> > father;
        bool found = false;
        auto state_is_target = [&](const string &s) {return s == end;};
        auto state_extend = [&](const string &s) {
        unordered_set<string> result;
        for (size_t i = 0; i < s.size(); ++i) {
            string new_word(s);
            for (char c = 'a'; c <= 'z'; c++) {
                if (c == new_word[i]) continue;
                    swap(c, new_word[i]);
                if ((dict.count(new_word) > 0 || new_word == end) && !visited.count(new_word)) {
                    result.insert(new_word);
                }
                swap(c, new_word[i]);
                }
            }
            return result;
        };
        
        current.insert(start);
        while (!current.empty() && !found) {
      
        for (const auto& word : current)
            visited.insert(word);
            for (const auto& word : current) {
                const auto new_states = state_extend(word);
                for (const auto &state : new_states) {
                if (state_is_target(state)) found = true;
                    next.insert(state);
                    father[state].push_back(word);
                    // visited.insert(state); 
                }
            }
            current.clear();
            swap(current, next);
        }
        vector<vector<string> > result;
        if (found) {
            vector<string> path;
            gen_path(father, path, start, end, result);
        }
        return result;
    }
    
private:
void gen_path(unordered_map<string, vector<string> > &father,
    vector<string> &path, const string &start, const string &word,
    vector<vector<string> > &result) {
        path.push_back(word);
        if (word == start) {
            result.push_back(path);
            reverse(result.back().begin(), result.back().end());
        }
        else{
            for (const auto& f : father[word]) {
                gen_path(father, path, start, f, result);
            }
        }
        path.pop_back();
    }
};
