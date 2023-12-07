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


node* fun(vector<int>& preorder, int & i, int bound){
    if(i == preorder.size() || preorder[i] > bound) return NULL;
    node* root = newNode(preorder[i++]);
    root->left = fun(preorder, i, root->data);
    root->right = fun(preorder, i, bound);
    return root;
}

node* bstFromPreorder(vector<int>& preorder) {
    int i = 0;
    return fun(preorder, i, INT_MAX);
}

void inOrderTrav(node * curr, vector < int > & inOrder) {
  if (curr == NULL)
    return;

  inOrderTrav(curr -> left, inOrder);
  inOrder.push_back(curr -> data);
  inOrderTrav(curr -> right, inOrder);
}

int main() {

  vector<int> arr = {8,5,1,7,10,12};
  node* data = bstFromPreorder(arr);

  vector < int > inOrder;
  inOrderTrav(data, inOrder);

  cout << "The inOrder Traversal is : ";
  for (int i = 0; i < inOrder.size(); i++) {
    cout << inOrder[i] << " ";
  }

  return 0;
}