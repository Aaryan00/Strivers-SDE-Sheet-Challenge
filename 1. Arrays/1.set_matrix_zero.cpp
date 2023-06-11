#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void MakeZeros(vector<vector<int> >& matrix) {
        int col = 1;
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i=0;i<n;i++){
            if(matrix[i][0] == 0){
                col = 0;
            }
            for(int j=1;j<m;j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=1;j--){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
            if(col == 0){
                matrix[i][0] = 0;
            }
        }
    }
};

int main()
{
    int m = 4, n = 3;
    vector<vector<int>> matrix = {
        {1,1,2,0},
        {0,4,5,2},
        {1,3,1,5}
    };

    Solution obj;
    obj.MakeZeros(matrix);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
