/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)return l2;
        if(l2 == NULL) return l1;
        ListNode *tmp = l1;
        if(l1->val > l2-> val){
            tmp = l2;
            l2 = l2->next;
        }else{
            l1 = l1->next;
        }
        ListNode *res = tmp;
        // l1 = l1->next;
        while(l1!=NULL && l2 != NULL){
            if(l1->val <= l2->val){
                tmp->next = l1;
                tmp = l1;
                l1 = l1->next;
            }else{
                tmp->next = l2;
                tmp = l2;
                l2= l2->next;
            }
        }
        if(l1 == NULL && l2 == NULL){
            return res;
        }else if(l1 == NULL){
            tmp->next = l2;
            return res;
        }else{
            tmp->next = l1;
            return res;
        }
    }
};