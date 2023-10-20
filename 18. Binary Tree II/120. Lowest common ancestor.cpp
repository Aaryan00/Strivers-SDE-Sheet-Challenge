#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

node* lowestCommonAncestor(node* root, node* p, node* q) {
    //base case
    if (root == NULL || root == p || root == q) {
        return root;
    }
    node* left = lowestCommonAncestor(root->left, p, q);
    node* right = lowestCommonAncestor(root->right, p, q);

    //result
    if(left == NULL) {
        return right;
    }
    else if(right == NULL) {
        return left;
    }
    else { //both left and right are not null, we found our result
        return root;
    }
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
  node* data = lowestCommonAncestor(root, root -> right -> right -> right, root -> left);
  cout << "The lowest common ancestor is "<<data->data;

  return 0;
}