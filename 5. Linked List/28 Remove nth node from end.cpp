#include <bits/stdc++.h>
using namespace std;

/* Link list node */
class Node {
public:
	int data;
	Node* next;
};

/* Given a reference (pointer to pointer) to the head
of a list and an int, push a new node on the front
of the list. */
void push(Node** head_ref, int new_data)
{
	/* allocate node */
	Node* new_node = new Node();

	/* put in the data */
	new_node->data = new_data;

	/* link the old list of the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

Node* removenode(Node* head, int n) {
        Node *start = new Node();
        start->next = head;
        int count = 0;
        Node * fast = start;
        Node * slow = start;
        while(fast->next != NULL){
            fast = fast->next;
            if(count >= n){
                slow = slow->next;
            }
            count++;
        }
        slow->next = slow->next->next;
        return start->next;
}

/* Driver code*/
int main()
{
	/* Start with the empty list */
	Node* head = NULL;

	/* Use push() to construct below list
	89->2->1->3->1 */
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);
	// push(&head, 26);
	// push(&head, 1);
	// push(&head, 89);


    head = removenode(head, 3);

    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
	return 0;
}
