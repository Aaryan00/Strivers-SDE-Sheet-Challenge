#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

node* lowestCommonAncestor(node* root, node* p, node* q) {
    if(root == NULL) return NULL;
    if(root->data > p->data && root->data > q->data) return lowestCommonAncestor(root->left, p, q);
    if(root->data < p->data && root->data < q->data) return lowestCommonAncestor(root->right, p, q);
    return root;
}

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}

int main() {

  struct node * root = newNode(6);
  root -> left = newNode(2);
  root -> left -> left = newNode(0);
  root -> left -> right = newNode(4);
  root -> right = newNode(8);

  node* data = lowestCommonAncestor(root, root->left, root -> left -> right);
  cout<<data->data;
  return 0;
}