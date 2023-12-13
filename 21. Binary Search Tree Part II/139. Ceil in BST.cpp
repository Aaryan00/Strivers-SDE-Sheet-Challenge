#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

int findCeil(node* root, int X){
    if(root == NULL) return -1;
    int a = -1;
    while(root) {
        if (root->data > X)
        {
            a = root->data;
            root = root->left; ;
        }
        else if (root->data < X) // go to right subtree
        {
            root = root->right;
        } else {
            a=root->data;
            return a;
        }
    }
    return a;
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
  int data = findCeil(root, 5);
  cout<<data;
  return 0;
}