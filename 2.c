/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *t1=l1;
    struct ListNode *t2=l2;
    int he;
    int jinwei=0;
    struct ListNode *head=NULL;
    struct ListNode *cur;
    while(t1!=NULL || t2!=NULL) {
        if(t1==NULL) he=t2->val+jinwei;
        if(t2==NULL) he=t1->val+jinwei;
        if(t1!=NULL && t2!=NULL) he=t1->val+t2->val+jinwei;
        if(he>=10) {
            he=he%10;
            jinwei=1;    
        } else {
            jinwei=0;
        }
        struct ListNode *node=malloc(sizeof(struct ListNode));
        node->val=he;
        node->next=NULL;
        if(head==NULL) {
            head=node;
            cur=head;
        } else {
            cur->next=node;
            cur=cur->next;
        }
        if(t1!=NULL) t1=t1->next;
        if(t2!=NULL) t2=t2->next;
    }
    if(jinwei!=0) {
        struct ListNode *node=malloc(sizeof(struct ListNode));
        node->val=jinwei;
        node->next=NULL;
        cur->next=node;
    }
    return head;
}