/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    int pos=-1;
    struct ListNode *slow=head;
    struct ListNode *fast=head;
    while(fast!=NULL && fast->next!=NULL) {
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow) {
            pos=1;
            break;
        }
    }
    if(pos==-1) return NULL;
    slow=head;
    while(slow!=fast) {
        slow=slow->next;
        fast=fast->next;
    }
    return slow;
}