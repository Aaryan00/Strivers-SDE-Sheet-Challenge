#include <bits/stdc++.h>

using namespace std;

class Solution {
  void solve(int i, int j, vector < vector < int >> & a, int n, vector < string > & ans, string move,
    vector < vector < int >> & vis, int di[], int dj[]) {
    if (i == n - 1 && j == n - 1) {
      ans.push_back(move);
      return;
    }
    string dir = "DLRU";
    for (int ind = 0; ind < 4; ind++) {
      int nexti = i + di[ind];
      int nextj = j + dj[ind];
      if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] && a[nexti][nextj] == 1) {
        vis[i][j] = 1;
        solve(nexti, nextj, a, n, ans, move + dir[ind], vis, di, dj);
        vis[i][j] = 0;
      }
    }

  }
  public:
    vector < string > findPath(vector < vector < int >> & m, int n) {
      vector < string > ans;
      vector < vector < int >> vis(n, vector < int > (n, 0));
      int di[] = {
        +1,
        0,
        0,
        -1
      };
      int dj[] = {
        0,
        -1,
        1,
        0
      };
      if (m[0][0] == 1) solve(0, 0, m, n, ans, "", vis, di, dj);
      return ans;
    }
};

int main() {
  int n = 4;

 vector < vector < int >> m = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
   
  Solution obj;
  vector < string > result = obj.findPath(m, n);
  if (result.size() == 0)
    cout << -1;
  else
    for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
  cout << endl;

  return 0;
}


// when need to return answer in matrix
// in this the input is getting changed but this can be fix by usig same logic as above

// #include <bits/stdc++.h> 
// void help(int i, int j, int n,vector<vector<int> > &maze,vector<vector<int> > &visited, vector<vector<int>> &ans)
// {
//   if(i<0 || j<0 || i>=n || j>=n || maze[i][j]==0 )
//   return ;
//   else if(i==n-1 && j==n-1)
//   {
//     vector<int> temp;
//     visited[i][j]=1;
//     for(int k=0;k<n;k++)
//     {
//       for(int l=0;l<n;l++)
//       {
//         temp.push_back(visited[k][l]);
//       }
//     }
//     visited[i][j]=0;
//     ans.push_back(temp);
//     return;
//   }
//   else
//   {
//       maze[i][j]=0;
//       //down
//       visited[i][j]=1;
//       help(i+1,j,n,maze,visited,ans);
//       visited[i][j]=0;
//       //left
//       visited[i][j]=1;
//       help(i,j-1,n,maze,visited,ans);
//       visited[i][j]=0;
//       //right
//       visited[i][j]=1;
//       help(i,j+1,n,maze,visited,ans);
//       visited[i][j]=0;
//       //Up
//       visited[i][j]=1;
//       help(i-1,j,n,maze,visited,ans);
//       visited[i][j]=0;
//       maze[i][j]=1;
//   }

// }
// vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
//   // Write your code here.
//    vector<vector<int>> visited(n,vector<int>(n,0));
//     vector<vector<int>> ans;
//     help(0,0,n,maze,visited,ans);
//     return ans;
// }