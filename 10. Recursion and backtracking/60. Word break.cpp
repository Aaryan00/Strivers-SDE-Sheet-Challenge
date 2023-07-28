#include <bits/stdc++.h> 
using namespace std;

void helper(int ind, string &s, vector<string> &dictionary, vector<string> &ans, string &ans_helper){
  if (ind == s.size()) {
      ans.push_back(ans_helper);
      return;
  }
    string temp = "";
    for(int i=ind; i<s.length();i++){
        temp = temp + s[i];
        if (find(dictionary.begin(), dictionary.end(), temp) != dictionary.end()){
            // ans_helper = ans_helper + temp + ' ';
            string c = ans_helper + temp + " ";
            helper(i+1, s, dictionary, ans, c);
        }
    }

}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // Write your code here
    string ans_helper = "";
    vector<string>ans;
    helper(0, s, dictionary, ans, ans_helper);
    return ans;
}


int main(){
    string s = "godisnowherenowhere";
    vector<string>dictionary = {"god", "is", "now", "no", "where", "here"};
    vector<string>ans = wordBreak(s, dictionary);
    for(int i=0; i < ans.size(); i++)
        cout << ans.at(i) <<endl;
    return 0;
}