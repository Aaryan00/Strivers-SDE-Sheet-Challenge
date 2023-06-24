#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int val;
        Node* next;
        Node* random;
        Node(int value) {
            val = value;
            next = NULL;
            random = NULL;
        }
};

Node* copyRandomList(Node* head) {
        if(head == NULL) return head;
        if(head->next == NULL){
             Node *head2 = new Node(head->val);
             if(head->random != NULL){
                head2->random = head2;
             }
             return head2;
        } 
        Node *temp = head;
        Node *second = temp->next;
        while(temp != NULL){
            Node *head2 = new Node(temp->val);
            second = temp->next;
            temp->next = head2;
            head2->next = second;
            temp = second;
        }
        temp = head;
        while(temp != NULL){
            if (temp->random == NULL){
                temp->next->random = temp->random;
            }else{
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }
        temp = head;
        Node *head2 = temp->next;
        second = temp;
        while(temp != NULL){
           second = temp->next->next;
           if(second == NULL){
                temp->next->next = second;
           }else{
                temp->next->next = second->next;
           }
           temp->next = second;
           temp = temp->next;
        }
        return head2;

}

void printList(Node* head) {
    while(head != NULL) {
        cout<<head->val<<':';
        head->next != NULL ? cout<<head->next->val:cout<<"NULL";
        head->random != NULL ? cout<<","<<head->random->val:cout<<",NULL";
        cout<<endl;
        head = head->next;
    }
}

int main() {
    Node* head = NULL;
    
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    
    head = node1;
    head->next = node2;
    head->next->next = node3;
    head->next->next->next = node4;
    
    head->random = node4;
    head->next->random = node1;
    head->next->next->random = NULL;
    head->next->next->next->random = node2;
    
    cout<<"Original list:(current node:node pointed by next pointer,node pointed by random pointer)";
    printList(head);
    
    cout<<"Copy list:(current node:node pointed by next pointer,node pointed by random pointer)";
    Node* newHead = copyRandomList(head);
    printList(newHead);
    return 0;
}