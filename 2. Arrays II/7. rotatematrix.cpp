#include<bits/stdc++.h>

using namespace std;
void rotate(vector < vector < int >> & mat) {
    int n = mat.size();
    int m= mat[0].size();
    // //transposing the matrix
    //  for(int i=0;i<n;i++){
    //         for(int j=0;j<i;j++){
    //             swap(mat[i][j],mat[j][i]);
    //         }
    //     }
    //     for(int i=0;i<n;i++){
    //         int l = 0;
    //         int r = m-1;
    //         while(l<=r){
    //             swap(mat[i][l],mat[i][r]);
    //             l++;
    //             r--;
    //         }
    //     }


 int left = 0 , right = m-1 , top  = 0 ,bottom = n-1;

    while(left < right && top < bottom ){
        int temp = mat[top][left];
        for(int col = left+1; col <= right; col++){
            int k = mat[top][col];
            mat[top][col] = temp;
            temp = k;
        }
        top++;

        for(int row = top; row <= bottom; row++){
            int k = mat[row][right];
            mat[row][right] = temp;
            temp = k;
        }
        right--;

        for(int col = right; col >= left; col--){
            int k = mat[bottom][col];
            mat[bottom][col] = temp;
            temp = k;
        }
        bottom--;

        for(int row = bottom; row >= top; row--){
            int k = mat[row][left];
            mat[row][left] = temp;
            temp = k;
        }
        left++;

        mat[top-1][left-1] = temp;
    }


}

int main() {
    vector < vector < int >> arr;
    arr =  {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotate(arr);
    cout << "Rotated Image" << endl;
    for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr[0].size(); j++) {
        cout << arr[i][j] << " ";
    }
    cout << "n";
    }

}