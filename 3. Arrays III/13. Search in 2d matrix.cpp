#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void searchtarget(vector<vector<int> >& matrix, int target) {
         int n = matrix.size();
        int m = matrix[0].size();
        int low = 0,high = (n*m)-1;
        while(low<=high){
            int mid = (low+(high-low)/2);
            if(matrix[mid/m][mid%m] == target){
                cout<<"Yes, the target  exist in matrix";
                return;
            }else if(matrix[mid/m][mid%m]< target) {
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        cout<<"No, the target not exist in matrix";
        return;
    }
};

int main()
{
    int m = 4, n = 3;
    vector<vector<int>> matrix = {
        {1,3,5,7},
        {10,11,16,21},
        {23,30,34,60}
    };

    int target = 20;

    Solution obj;
    obj.searchtarget(matrix, target);

    return 0;
}
