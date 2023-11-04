#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}
node* constructTree(int inStart, int inEnd, int postStart, int postEnd, vector<int>& inorder, vector<int>& postorder, unordered_map<int, int>& mp) {
 if(inStart > inEnd || postStart > postEnd) return NULL;
    node* curr =  newNode(postorder[postEnd]);
    int split = mp[postorder[postEnd]];
    int leftElements = split - inStart;
    int rightElements = inEnd - split;
    curr->left = constructTree(inStart, inStart + leftElements-1, postStart, postStart + leftElements-1,     inorder, postorder, mp);
    curr->right = constructTree(inEnd-rightElements+1, inEnd, postEnd-rightElements, postEnd-1, inorder, postorder, mp);
    return curr;
}

node * buildTree(vector < int > & postorder, vector < int > & inorder) {
  int postStart = 0, postEnd = postorder.size() - 1;
  int inStart = 0, inEnd = inorder.size() - 1;

  unordered_map<int, int> mp;
  for (int i = inStart; i <= inEnd; i++) {
    mp[inorder[i]] = i;
  }

  return constructTree(inStart,inEnd, postStart, postEnd, inorder, postorder, mp);
}

int main() {

  vector<int> postorder{40,50,20,60,30,10};
  vector<int> inorder{40,20,50,10,60,30};
  node * root = buildTree(postorder, inorder);
  return 0;
}
