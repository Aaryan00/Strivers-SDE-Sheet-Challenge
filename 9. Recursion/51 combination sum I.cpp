#include<bits/stdc++.h>

using namespace std;
class Solution {
  public:
    void findCombination(int ind, int target, vector < int > & arr, vector < vector < int >> & ans, vector < int > & ds) {
      if (ind == arr.size()) {
        if (target == 0) {
          ans.push_back(ds);
        }
        return;
      }
      // pick up the element 
      // If input consist of negative then remove this if case
      if (arr[ind] <= target) {
        ds.push_back(arr[ind]);
        findCombination(ind, target - arr[ind], arr, ans, ds);
        ds.pop_back();
      }

      findCombination(ind + 1, target, arr, ans, ds);

    }
  public:
    vector < vector < int >> combinationSum(vector < int > & candidates, int target) {
              // sort(candidates.begin(), candidates.end());  //by me
      vector < vector < int >> ans;
      vector < int > ds;
      findCombination(0, target, candidates, ans, ds);
      return ans;
    }
};
int main() {
  Solution obj;
  vector < int > v {-2,2};
  int target = 0;

  vector < vector < int >> ans = obj.combinationSum(v, target);
  cout << "Combinations are: " << endl;
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++)
      cout << ans[i][j] << " ";
    cout << endl;
  }
}
