/*
*
* Tag: Math
* Time: O(n*m)
* Space: O(1)
*/
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

const int WIDTH = 1;
const int LENGTH = 1;

int getCubeAreas(int w, int l, int h){
    return 2*(w*l + w*h + l*h);
}

int getRectangleArea(int w, int l){
    return w*l;
}

// Complete the surfaceArea function below.
int surfaceArea(vector<vector<int>> cubes) {
    int ans = 0;
    if(cubes.size() == 0){
        return ans;
    }
    int r = cubes.size(), c = cubes[0].size();
    
    for(int i = 0; i < r; ++ i){
        for(int j = 0; j < c; ++ j){
            
            ans += getCubeAreas(WIDTH, LENGTH, cubes[i][j]);
            if(j > 0){
                ans -= 2*getRectangleArea(WIDTH, min(cubes[i][j], cubes[i][j - 1]));
            }
            
            if(i > 0){
                ans -= 2*getRectangleArea(WIDTH, min(cubes[i][j], cubes[i - 1][j]));
            }
	   }
    }
    
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string HW_temp;
    getline(cin, HW_temp);

    vector<string> HW = split_string(HW_temp);

    int H = stoi(HW[0]);

    int W = stoi(HW[1]);

    vector<vector<int>> A(H);
    for (int i = 0; i < H; i++) {
        A[i].resize(W);

        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = surfaceArea(A);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
