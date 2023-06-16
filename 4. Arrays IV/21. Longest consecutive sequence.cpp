#include<bits/stdc++.h>
using namespace std;

int longestConsecutive(vector < int > & nums) {
    set<int> data;
    for(int i=0;i<nums.size();i++){
        data.insert(nums[i]);
    }

    int maximum = 0;
    for(int i=0;i<nums.size();i++){
        int current = 1;
        int current_num = nums[i];
        if(!data.count(nums[i]-1)){
            while(data.count(current_num+1)){
                current+=1;
                current_num+=1;
            }
        }
        maximum = max(maximum, current);
    }
    return maximum;
}

int main() {
  vector<int> arr{100,200,1,2,3,4};
  int lon = longestConsecutive(arr);
  cout << "The longest consecutive sequence is " << lon << endl;

}