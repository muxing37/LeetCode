/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *cur=head;
    struct ListNode *temp=NULL;
    struct ListNode *front=NULL;
    int count=0;
    while(cur!=NULL) {
        count++;
        if(temp!=NULL) temp=temp->next;
        if(front!=NULL) front=front->next;
        if(count==n) temp=head;
        if(count==n+1) front=head;
        cur=cur->next;
    }
    if(count==1) return NULL;
    if(count==n) {
        head=head->next;
    } else {
        front->next=temp->next;
    }
    return head;
}