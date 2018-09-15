/*
* Algorithm: Brute foce
* Time complexity:O(n^2)
* Memory complexity:O(n)
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int rows = board.size();
        if(9 != rows) return false;
        int cols = board[0].size();
        if(9 != cols) return false;
        //1.check duplications in each row
        int dup[10];//hash for 1 to 9
        for(int ir = 0; ir < rows; ++ir) {
            for(int i = 0; i <= 9; ++i)
                dup[i] = 0;
            for(int i = 0; i < 9; ++i){
                char c = board[ir][i];
                if(c == '.')
                    ++dup[0];
                else {
                    int hash = c - '0';
                    if(dup[hash] == 1) {
                        return false;
                    } else {
                        ++dup[hash];
                    }
                }
            }
        }
        //2. check duplications in each cols
        for(int ic = 0; ic < cols; ++ic) {
            for(int i = 0; i <= 9; ++i)
                dup[i] = 0;
            for(int i = 0; i < 9; ++i){
                char c = board[i][ic];
                if(c == '.')
                    ++dup[0];
                else {
                    int hash = c - '0';
                    if(dup[hash] == 1) {
                        return false;
                    } else {
                        ++dup[hash];
                    }
                }
            }
        }
        //3. check duplications in each 3 * 3 grid
        for(int ir = 0; ir < rows; ir += 3) {
            for(int ic = 0; ic < cols; ic += 3) {
                for(int i = 0; i <= 9; ++i)
                    dup[i] = 0;
                for(int iir = 0; iir < 3; ++iir) {
                    for(int iic = 0; iic < 3; ++iic) {
                        char c = board[ir + iir][ic + iic];
                        if(c == '.')
                            ++dup[0];
                        else {
                            int hash = c - '0';
                            if(dup[hash] == 1) {
                                return false;
                            } else {
                                ++dup[hash];
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};
