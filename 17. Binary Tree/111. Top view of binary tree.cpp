#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

vector<int> bottomSideView(node *root) {
    vector<int> ans; 
    if(root == NULL) return ans; 
    map<int,int> mpp; 
    queue<pair<node*, int>> q; 
    q.push({root, 0}); 
    while(!q.empty()) {
        auto it = q.front(); 
        q.pop(); 
        node* node = it.first; 
        int line = it.second; 
        if(!mpp[line])mpp[line] = node->data; 
        
        if(node->left != NULL) {
            q.push({node->left, line-1}); 
        }
        if(node->right != NULL) {
            q.push({node->right, line + 1}); 
        }
        
    }
    
    for(auto it : mpp) {
        ans.push_back(it.second); 
    }
    return ans;  
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
  inorder = bottomSideView(root);

  cout << "The left view is: ";
  for (int i = 0; i < inorder.size(); i++) {
    cout << inorder[i] << " ";
  }

  return 0;
}