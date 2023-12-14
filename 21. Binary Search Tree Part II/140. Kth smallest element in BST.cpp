#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

node* kk(node* root, int& k){
    if(root==NULL) return NULL;

    node* left=kk(root->left,k);
    if(left!=NULL) return left;
    k--;
    if(k==0)  return root;
    
    return kk(root->right,k);
}
int kthSmallest(node* root, int k) {
    node* small = kk(root, k);
    if(small == NULL){
        return -1;
    }
    return small->data;
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
  int data = kthSmallest(root, 2);
  cout<<data;
  return 0;
}