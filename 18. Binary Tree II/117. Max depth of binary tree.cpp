#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

int maxDepth(node* root) {
    if(root == NULL) return 0; 
    
    int lh = maxDepth(root->left); 
    int rh = maxDepth(root->right); 
    
    return 1 + max(lh, rh); 
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
  root -> left = newNode(3);
  root -> left -> left = newNode(5);
  root -> left -> left -> left = newNode(7);
  root -> right = newNode(2);
  root -> right -> right = newNode(4);
  root -> right -> right -> right = newNode(6);
  vector<vector<int>> traversal;
  int depth = maxDepth(root);
  cout << "The level order traversal of the Binary Tree is "<<depth;

  return 0;
}