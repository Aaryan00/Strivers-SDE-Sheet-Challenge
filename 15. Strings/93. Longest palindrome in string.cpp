#include<bits/stdc++.h>
using namespace std;


string check_palindrome(string s){
    int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int start = 0;
        int end = 0;
        
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start  = i;
                end = 2;
            }
        }
        
        for (int diff = 2; diff < n; diff++) {
            for (int i = 0; i < n - diff; i++) {
                int j = i + diff;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    start  = i;
                    end = diff +1;
                }
            }
        }
        return s.substr(start, end);
}

int main(){
    string s = "judgegduj";
    string ans = check_palindrome(s);
    cout<<"Given string is the largest palindrome string: "<<ans;
}