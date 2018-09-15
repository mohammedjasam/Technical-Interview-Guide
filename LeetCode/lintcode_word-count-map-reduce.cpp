/*
*
* Tag: Big Data
*
*/
/**
 * Definition of Input:
 * template<class T>
 * class Input {
 * public:
 *     bool done(); 
 *         // Returns true if the iteration has elements or false.
 *     void next();
 *         // Move to the next element in the iteration
 *         // Runtime error if the iteration has no more elements
 *     T value();
 *        // Get the current element, Runtime error if
 *        // the iteration has no more elements
 * }
 */
class WordCountMapper: public Mapper {
public:
    void Map(Input<string>* input) {
        // Write your code here
        // Please directly use func 'output' to 
        // output the results into output buffer.
        // void output(string &key, int value);
        Input<string>* p = input;
        string key = "", chunk = "";
        while(!p->done()){
            chunk = p->value();
            for(int i = 0; i <= chunk.size(); ++ i){
                if(chunk[i] == ' ' || i == chunk.size()){
                    output(key,1);
                    key = "";
                }else{
                    key += chunk[i];
                }
            }
            p->next();
        }
    }
};


class WordCountReducer: public Reducer {
public:
    void Reduce(string &key, Input<int>* input) {
        // Write your code here
        // Please directly use func 'output' to 
        // output the results into output buffer.
        // void output(string &key, int value);
        int res = 0;
        Input<int>* p = input;
        while(!p->done()){
            res += p->value();
            p->next();
        }
        output(key,res);
    }
};
