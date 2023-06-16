#include <bits/stdc++.h>

using namespace std;
class Solution {
  public:
    int lengthofLongestSubstring(string s) {
    //   vector < int > mpp(256, -1);
              unordered_map<char,int> hashmap;
        int left = 0, right = 0;
        int maxi = 0;
        int n = s.size();
        while(right< n){
            if(hashmap.find(s[right])!=hashmap.end()){
                left = max(hashmap[s[right]]+1, left);
            }
            hashmap[s[right]] = right;
            maxi = max(maxi, right - left + 1);
            right++;
        }
        return maxi;
    }
};

int main() {
  string str = "codingninjas";
  Solution obj;
  cout << "The length of the longest substring without repeating characters is " << obj.lengthofLongestSubstring(str);
  return 0;
}