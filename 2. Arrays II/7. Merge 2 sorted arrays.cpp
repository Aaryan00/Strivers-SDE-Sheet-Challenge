#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, vector<int>& nums2, int n, int m) {
        m--;
        n--;
        for(int i=nums1.size()-1;i>=0;i--){
            if (n<0) return;
            if (m>=0 && nums1[m]> nums2[n]){
                nums1[i] = nums1[m];
                m--;
            }else{
                nums1[i] = nums2[n];
                n--;
            }
        }
    }
};

int main()
{
    vector<int> arr1 = {1, 4, 8, 10, 0, 0 ,0};
    vector<int> arr2 = {2, 3, 9};
    int n = 3, m = 4;
    Solution obj;
    obj.merge(arr1, arr2, n, m);
    cout << "The merged arrays are: " << "\n";
    cout << "arr1[] = ";
    for (int i = 0; i < (m+n); i++) {
        cout << arr1[i] << " ";
    }
    cout << "\narr2[] = ";
    for (int i = 0; i < n; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    return 0;
}