/*
*
* Tag: Hash
* Time: O(n^2)
* Space: O(n^2)
*/
class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food) {
        w = width, h = height;
        cntfood = 0;
        fdid = 0;
        snake.resize(1);
        snake[0] = make_pair(0, 0);
        foodvec = food;
        mpstate.clear();
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        int hx = snake[0].first, hy = snake[0].second;
        vector<pair<int,int>> tmpsnk;
        unordered_map<int,unordered_set<int>> tmpmpstat;
        if(direction == "U")
            -- hx;
        else if(direction == "D")
            ++ hx;
        else if(direction == "L")
            -- hy;
        else
            ++ hy;
        if(hx < 0 || hx >= h || hy < 0 || hy >= w)
            return -1;
        int id = 0, len;
        tmpmpstat.clear();
        if(fdid < foodvec.size() && foodvec[fdid].first == hx && foodvec[fdid].second == hy ){
            tmpsnk.resize(snake.size() + 1);
            tmpsnk[id ++] = make_pair(hx, hy);
            ++ fdid;
            ++ cntfood;
            len = snake.size();
        }else{
            tmpsnk.resize(snake.size());
            tmpsnk[id ++] = make_pair(hx, hy);
            len = snake.size() - 1;
        }
        for(int i = 0; i < len; ++ i, ++ id)
                tmpsnk[id] = snake[i];
        for(int i = tmpsnk.size() - 1; i > 0 ; -- i){
            tmpmpstat[tmpsnk[i].first].insert(tmpsnk[i].second);
        }
        if(tmpmpstat[hx].find(hy) != tmpmpstat[hx].end())
            return -1;
        tmpmpstat[tmpsnk[0].first].insert(tmpsnk[0].second);
        snake = tmpsnk;
        mpstate = tmpmpstat;
        return cntfood;
    }
private:
    int cntfood;
    int w, h, fdid;
    vector<pair<int,int>> snake, foodvec;
    unordered_map<int,unordered_set<int>> mpstate;
};
