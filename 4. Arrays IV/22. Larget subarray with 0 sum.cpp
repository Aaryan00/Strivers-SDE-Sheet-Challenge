//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&nums, int n)
    {   
      int maxi = 0;
        int sum = 0;
        unordered_map<int,int>hashmap;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum == 0){
                maxi = i+1;
            }else{
                if(hashmap.find(sum) != hashmap.end()){
                    maxi = max(maxi, i-hashmap[sum]);
                }else{
                    hashmap[sum] = i;
                }
            }
        }
        return maxi;
    }
};


//{ Driver Code Starts.

int main()
{
        int m;
        m= 8;
        vector<int> array1 = {15,-2,2,-8,1,7,10,23};

        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    return 0; 
}



// } Driver Code Ends