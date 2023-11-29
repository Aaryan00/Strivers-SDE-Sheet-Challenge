#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

node* searchBST(node* root, int val) {
    if(root==NULL) return NULL;

    if(root->data == val) return root;

    else if(root->data > val) return searchBST(root->left, val);

    else return searchBST(root->right, val);
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

  struct node * root = newNode(4);
  root -> left = newNode(2);
  root -> left -> left = newNode(1);
  root -> left -> right = newNode(3);
  root -> right = newNode(7);

  node* data = searchBST(root, 2);

  vector < int > inOrder;
  inOrderTrav(data, inOrder);

  cout << "The inOrder Traversal is : ";
  for (int i = 0; i < inOrder.size(); i++) {
    cout << inOrder[i] << " ";
  }

  return 0;
}