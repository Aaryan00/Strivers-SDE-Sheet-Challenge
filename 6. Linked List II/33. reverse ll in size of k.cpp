#include<bits/stdc++.h>
using namespace std;

class node {
    public:
        int num;
        node* next;
        node(int a) {
            num = a;
            next = NULL;
        }
};
//utility function to insert node in the list
void insertNode(node* &head,int val) {
    node* newNode = new node(val);
    if(head == NULL) {
        head = newNode;
        return;
    }
    
    node* temp = head;
    while(temp->next != NULL) temp = temp->next;
    
    temp->next = newNode;
    return;
}
//utility function to find length of the list
int lengthOfLinkedList(node* head) {
    int length = 0;
    while(head != NULL) {
        ++length;
        head = head->next;
    }
    return length;
}
//utility function to reverse k nodes in the list
node* reverseKNodes(node* head,int k) {
    if(head == NULL||head->next == NULL) return head;
    
    int length = lengthOfLinkedList(head);
    
    node* dummyHead = new node(0);
    dummyHead->next = head;
    
    node* pre = dummyHead;
    node* cur;
    node* nex;
    
    while(length >= k) {
        cur = pre->next;
        nex = cur->next;
        for(int i=1;i<k;i++) {
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
        }
        pre = cur;
        length -= k;
    }
    if (length <= 1) return dummyHead->next;
    cur = pre->next;
    nex = cur->next;
    for(int i=1;i<length;i++) {
        cur->next = nex->next;
        nex->next = pre->next;
        pre->next = nex;
        nex = cur->next;
    }

    return dummyHead->next;
}

//utility function to print the list
void printLinkedList(node* head) {
    while(head->next != NULL) {
        cout<<head->num<<"->";
        head = head->next;
    }
    cout<<head->num<<"\n";
}



int main() {
    node* head = NULL;
    int k = 5;
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,3);
    insertNode(head,4);
    insertNode(head,5);
    insertNode(head,6);
    insertNode(head,7);
    insertNode(head,8);
    printLinkedList(head);

    
    cout<<"Original Linked List: "; printLinkedList(head);
    cout<<"After Reversal of k nodes: "; 
    node* newHead = reverseKNodes(head,k);
    printLinkedList(newHead);
    
    return 0;
}

// the quyestion can be in second way, that k is not fix, it is changing, then this is the anse
/*
#include <bits/stdc++.h>

****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************
int lengthOfLinkedList(Node* head) {
    int length = 0;
    while(head != NULL) {
        ++length;
        head = head->next;
    }
    return length;
}
Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	// Write your code here.
	if(head == NULL||head->next == NULL) return head;
    
    int length = lengthOfLinkedList(head);
    
    Node* dummyHead = new Node(0);
    dummyHead->next = head;
    
    Node* pre = dummyHead;
    Node* cur;
    Node* nex;
    int count=0;
	int hh = 0;
    while(true) {
		if (b[count] == 0){
			count++;
			if(count>=n) return dummyHead->next;
			continue;
		} 
        cur = pre->next;
        nex = cur->next;
        if (length > b[count]) {
			hh = b[count];
        } else {
			hh= length;
        }
        for(int i=1;i<hh;i++) {
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
        }
        pre = cur;
        length -= hh;
		count++;

		if(length ==0 || count>=n){

			return dummyHead->next;
		} 
    }
    return dummyHead->next;
}
*/