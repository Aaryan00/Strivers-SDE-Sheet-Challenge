#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

void recursion(node *root, int level, vector<int> &res)
{
    if(root==NULL) return ;
    if(res.size()==level) res.push_back(root->data);
    recursion(root->left, level+1, res);
    recursion(root->right, level+1, res);
}

vector<int> leftSideView(node *root) {
    vector<int> res;
    recursion(root, 0, res);
    return res;
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
  root -> right = newNode(3);
  root -> left -> left = newNode(4);
  root -> left -> right = newNode(5);
  root -> left -> right -> right = newNode(6);

  vector < int > inorder;
  inorder = leftSideView(root);

  cout << "The left view is: ";
  for (int i = 0; i < inorder.size(); i++) {
    cout << inorder[i] << " ";
  }

  return 0;
}