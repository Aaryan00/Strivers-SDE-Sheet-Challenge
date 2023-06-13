#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr) {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());

        for(int i=0;i<arr.size();i++){
            if(ans.empty() || ans.back()[1] < arr[i][0]){
                ans.push_back(arr[i]);
            }
            else{
                ans.back()[1] = max(arr[i][1], ans.back()[1]);
            }
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> arr = {{2, 3}, {4, 5}, {6, 7}, {8, 10}, {1,10}};
    vector<vector<int>> ans = obj.mergeOverlappingIntervals(arr);
    cout << "The merged intervals are: " << "\n";
    for (auto it : ans) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
    return 0;
}