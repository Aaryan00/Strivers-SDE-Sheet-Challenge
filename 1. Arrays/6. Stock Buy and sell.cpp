#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int stocks(vector<int>& nums) {
        int min_price = INT_MAX;
        int max_profit = 0;

        for(int i=0;i<nums.size();i++){
            min_price = min(min_price,nums[i]); 
            max_profit = max(max_profit, nums[i] - min_price);
        }
        return max_profit;
    }
};

int main()
{
    vector<int> nums ={17,20,11,9,12,6};
    Solution obj;
    cout<<"MAX profit is: "<<obj.stocks(nums);


    return 0;
}
