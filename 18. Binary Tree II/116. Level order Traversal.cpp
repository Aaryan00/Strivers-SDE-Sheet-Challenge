#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

 vector<vector<int>> levelOrder(node* root) {
        vector<vector<int>> ans; 
        
        if(root == NULL) 
            return ans; 
            
        queue<node*> q; 
        q.push(root); 
        
        while(!q.empty()) {
            int size = q.size();
                    vector<int> temp;
            while(size--){
                node *tempp = q.front(); 
                q.pop(); 
                
                if(tempp->left != NULL) 
                    q.push(tempp->left); 
                if(tempp->right != NULL) 
                    q.push(tempp->right); 
                    
                temp.push_back(tempp->data); 
            }
            ans.push_back(temp);
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
  root -> left = newNode(3);
  root -> left -> left = newNode(5);
  root -> left -> left -> left = newNode(7);
  root -> right = newNode(2);
  root -> right -> right = newNode(4);
  root -> right -> right -> right = newNode(6);
  vector<vector<int>> traversal;
  traversal = levelOrder(root);
  cout << "The level order traversal of the Binary Tree is ";

  return 0;
}
