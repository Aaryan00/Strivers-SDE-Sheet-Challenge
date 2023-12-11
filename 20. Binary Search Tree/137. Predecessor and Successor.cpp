#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

void findPreSuc(node* root, node*& pre, node*& suc, int key)
{
    if (root == NULL) return ;
    if (root->data > key)
    {
        suc = root ;
        findPreSuc(root->left, pre, suc, key) ;
    }
    else if (root->data < key) // go to right subtree
    {
        pre = root ;
        findPreSuc(root->right, pre, suc, key) ;
    }
    else{
        findPreSuc(root->left, pre, suc, key) ;
        findPreSuc(root->right, pre, suc, key) ;
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

  struct node * root = newNode(6);
  root -> left = newNode(2);
  root -> left -> left = newNode(0);
  root -> left -> right = newNode(4);
  root -> right = newNode(8);
  node* pre = nullptr;
  node* suc = nullptr;
  findPreSuc(root, pre, suc, 6);
  cout<<pre->data<<endl;
  cout<<suc->data;
  return 0;
}