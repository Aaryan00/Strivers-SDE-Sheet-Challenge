#include<bits/stdc++.h>

using namespace std;

// A structure to represent a job 
struct Job {
   int id; // Job Id 
   int dead; // Deadline of job 
   int profit; // Profit if job is over before or on deadline 
};

class Solution {
   public:
      static bool comparison(Job a, Job b) {
         return (a.profit > b.profit);
      }
      
      // Function to find the maximum profit and the number of jobs done
      pair<int, int> JobScheduling(Job arr[], int n) {
         sort(arr, arr + n, comparison);
         int maxi = arr[0].dead;
         
         for (int i = 1; i < n; i++) {
            maxi = max(maxi, arr[i].dead);
         }
         
         int slot[maxi + 1];
         for (int i = 0; i <= maxi; i++) {
            slot[i] = -1;
         }
         
         int countJobs = 0, jobProfit = 0;
         
         for (int i = 0; i < n; i++) {
            for (int j = arr[i].dead; j > 0; j--) {
               if (slot[j] == -1) {
                  slot[j] = i;
                  countJobs++;
                  jobProfit += arr[i].profit;
                  break;
               }
            }
         }
         
         return make_pair(countJobs, jobProfit);
      }
};

int main() {
   int n = 4;
   Job arr[n] = {{1,4,20},{2,1,10},{3,2,40},{4,2,30}};

   Solution ob;
   // Function call
   pair<int, int> ans = ob.JobScheduling(arr, n);
   cout << ans.first << " " << ans.second << endl;

   return 0;
}



// Without struct


// #include <bits/stdc++.h> 
// static bool comparison(vector<int> a, vector<int> b) {
//     return (a[1] > b[1]);
// }


// int jobScheduling(vector<vector<int>> &jobs)
// {
//     // Write your code here
//         int n=jobs.size();

//     sort(jobs.begin(), jobs.end(), comparison);
//     int maxi = jobs[0][0];
    
//     for (int i = 1; i < n; i++) {
//     maxi = max(maxi, jobs[i][0]);
//     }
    
//     int slot[maxi + 1];
//     for (int i = 0; i <= maxi; i++) {
//         slot[i] = -1;
//     }
    
//     int countJobs = 0, jobProfit = 0;
    
//     for (int i = 0; i < n; i++) {
//     for (int j = jobs[i][0]; j > 0; j--) {
//         if (slot[j] == -1) {
//             slot[j] = i;
//             countJobs++;
//             jobProfit += jobs[i][1];
//             break;
//         }
//     }
//     }
    
//     return jobProfit;
// }
