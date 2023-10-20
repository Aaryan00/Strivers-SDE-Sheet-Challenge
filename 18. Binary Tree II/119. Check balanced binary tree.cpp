#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

int dfsHeight (node *root) {

    if (root == NULL) return 0;
    
    int leftHeight = dfsHeight (root -> left);

    if (leftHeight == -1) 
        return -1;
    
    int rightHeight = dfsHeight (root -> right);

    if (rightHeight == -1) 
        return -1;
    
    if (abs(leftHeight - rightHeight) > 1)  
        return -1;

    return max (leftHeight, rightHeight) + 1;
}

bool isBalanced(node* root) {
        int a = dfsHeight(root);
        if(a == -1){
            return false;
        }
        return true;
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
  bool balanced = isBalanced(root);
  cout << "The Binary Tree is "<<balanced;

  return 0;
}