#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = 0, curr = 0;
        for(int i=0;i<nums.size();i++){
            curr += nums[i];
            if (maxi < curr)
                maxi = curr;
            if (curr < 0) curr = 0;
        }
        return maxi;
    }
};

int main()
{
    vector<int> num = {-2,1,-3,4,-1,2,1,-5,4};
    Solution obj;
    int n;
    n = obj.maxSubArray(num);
    cout<<"Largest subaaray sum is : "<<n;
    return 0;
}
