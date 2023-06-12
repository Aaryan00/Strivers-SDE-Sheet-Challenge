#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size()-1;

        while(low<=high){
            if(nums[low] == 0){
                if(low!=mid){
                    swap(nums[low], nums[mid]);
                }
                low++;
                mid++;
            }else if(nums[low] == 1){
                low++;
            }else{
                swap(nums[low], nums[high]);
                high--;
            }
        }
    }
};

int main()
{
    vector<int> nums ={2,2,1,0,1,1,1,0};
    Solution obj;
    obj.sortColors(nums);

    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }

    return 0;
}
