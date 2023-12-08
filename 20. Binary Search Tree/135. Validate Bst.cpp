#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

bool fun(node* root,long long minval,long long maxval){
    if(!root) return true;
    if(root->data>=maxval || root->data<=minval) return false;

    return(fun(root->left,minval,root->data) && fun(root->right,root->data,maxval));
}

bool isValidBST(node* root) {
    return fun(root,LONG_MIN,LONG_MAX);
}

void inOrderTrav(node * curr, vector < int > & inOrder) {
  if (curr == NULL)
    return;

  inOrderTrav(curr -> left, inOrder);
  inOrder.push_back(curr -> data);
  inOrderTrav(curr -> right, inOrder);
}

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}

int main() {

  struct node * root = newNode(1);
  root -> left = newNode(2);
  root -> left -> left = newNode(1);
  root -> left -> right = newNode(3);
  root -> right = newNode(7);

  bool data = isValidBST(root);
  cout<<data;
  return 0;
}