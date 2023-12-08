// 1. Using BFS

 Node* connect(Node* root) {
        if(!root) return NULL;
        queue<Node*> q;
        q.push(root);
        while(size(q)){
            Node* rightNode = nullptr;
            int ss = size(q);
            while(ss--){
                auto cur = q.front();
                q.pop();
                cur->next = rightNode;
                rightNode = cur;
                if(cur->left){
                    q.push(cur->right);
                    q.push(cur->left);
                }
            }
        }
        return root;
    }

// 2. Using DFS:
    Node* connect(Node* root) {
        if(!root) return nullptr;
        auto L = root -> left, R = root -> right, N = root -> next;
        if(L) {
            L -> next = R;                                // next of root's left is assigned as root's right
            if(N) R -> next = N -> left;                  // next of root's right is assigned as root's next's left (if root's next exist)
            connect(L);                                   // recurse left  - simple DFS 
            connect(R);                                   // recurse right
        }
        return root;
    }

// 3. Using BFS without Space:

Node* connect(Node* root) {
        auto head = root;
        for(; root; root = root -> left) 
            for(auto cur = root; cur; cur = cur -> next)   // traverse each level - it's just BFS taking advantage of next pointers          
                if(cur -> left) {                          // update next pointers of children if they exist               
                    cur -> left -> next = cur -> right;
                    if(cur -> next) cur -> right -> next = cur -> next -> left;
                }
                else break;                                // if no children exist, stop iteration                                                  
        
        return head;
    }
    
