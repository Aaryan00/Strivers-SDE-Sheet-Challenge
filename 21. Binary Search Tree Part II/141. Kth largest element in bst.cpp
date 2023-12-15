#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

node* kk(node* root, int& k){
       if(root==NULL) return NULL;
	
        node* right=kk(root->right,k);
        if(right)
        return right;
        k--;
        if(k==0)  return root;
        
        return kk(root->left,k);
    }
int kthLargest(node *root, int k) {
    node* large = kk(root, k);
    if(large == NULL){
        return -1;
    }
    return large->data;
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
  int data = kthLargest(root, 2);
  cout<<data;
  return 0;
}