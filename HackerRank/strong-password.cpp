/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/
#include <bits/stdc++.h>

using namespace std;

const int MIN_PASSWORD_LENGTH = 6;

int minimumNumber(int n, string password) {
    int ans = 0;
    if(!any_of(password.begin(), password.end(), ::isdigit)){
        ++ ans;
    }
    
    if(!any_of(password.begin(), password.end(), ::islower)){
        ++ ans;
    }
    
    if(!any_of(password.begin(), password.end(), ::isupper)){
        ++ ans;
    }
    
    struct isSpecialCharacters
    {
        string specialCharacters = "!@#$%^&*()-+";
        bool operator()(char val) const { 
            return specialCharacters.find(val) != string::npos; 
        }
    };
    if (!any_of(password.begin(), password.end(), isSpecialCharacters() )) {
        ++ ans;
    }
    
    if(password.size() + ans < MIN_PASSWORD_LENGTH){
        ans += MIN_PASSWORD_LENGTH - (password.size() + ans);
    }
    
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

    fout.close();

    return 0;
}
