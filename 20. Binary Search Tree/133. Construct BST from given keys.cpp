#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}

node* func(vector<int> &nums, int begin, int end){
    if (begin > end){
        return NULL;
    }
    if (begin == end){
        return newNode(nums[end]);
    }
    int middle = (begin + end)/2;
    node* root = newNode(nums[middle]);
    root->left = func(nums, begin, middle -1);
    root->right = func(nums, middle + 1, end);
    return root;
}

node* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0)return NULL;
        return func(nums, 0, nums.size()-1);
    }

void inOrderTrav(node * curr, vector < int > & inOrder) {
  if (curr == NULL)
    return;

  inOrderTrav(curr -> left, inOrder);
  inOrder.push_back(curr -> data);
  inOrderTrav(curr -> right, inOrder);
}

int main() {
  vector<int> arr = {-10,-3,0,5,9};
  node* data = sortedArrayToBST(arr);

  vector < int > inOrder;
  inOrderTrav(data, inOrder);

  cout << "The inOrder Traversal is : ";
  for (int i = 0; i < inOrder.size(); i++) {
    cout << inOrder[i] << " ";
  }

  return 0;
}