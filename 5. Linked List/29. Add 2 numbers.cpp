/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *addTwoNumbers(Node *num1, Node *num2)
{
    // Write your code here.
    if(num1==NULL)return num2;
    if(num2==NULL) return num1;
    Node* newhead = new Node();
    Node* temp = newhead;
    Node* l1=num1;
    Node*l2 = num2;
    int sum=0;
    int carry =0;
    while(l1!=NULL || l2!=NULL || carry){
        sum = carry;
        if(l1!=NULL){
            sum = sum + l1->data;
            l1=l1->next;
        }
        if(l2!=NULL){
            sum = sum + l2->data;
            l2=l2->next;
        }
        carry = sum/10;
        Node* node = new Node(sum%10);
        temp->next = node;
        temp = temp->next;
    }

    return newhead->next;
}
