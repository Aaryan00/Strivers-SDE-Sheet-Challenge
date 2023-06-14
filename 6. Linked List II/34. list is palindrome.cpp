#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    if(head == NULL)return true;
        LinkedListNode<int> *slow = head;
        LinkedListNode<int> *fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        LinkedListNode<int> *newhead = slow->next;
        LinkedListNode<int> *prev = NULL;
        LinkedListNode<int> *after = NULL;
        while(newhead != NULL){
            after = newhead->next;
            newhead->next = prev;
            prev = newhead;
            newhead = after;
        }
        // cout<<prev->next->val;
        // cout<<head->next->next;
        while(prev!= NULL){
            if(prev->data != head->data) return false;
            head = head->next;
            prev= prev->next;
        }
        return true;
}