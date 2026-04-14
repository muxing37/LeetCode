/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *tA=headA;
    int ta=0;
    struct ListNode *tB=headB;
    int tb=0;
    while(tA->next!=NULL) {
        tA=tA->next;
        ta++;
    }
    while(tB->next!=NULL) {
        tB=tB->next;
        tb++;
    }
    if(tA!=tB) return NULL;
    int i;
    int dis=ta-tb;
    if(dis<0){
        dis=-dis;
        struct ListNode *t=headB;
        for(i=0;i<dis;i++) {
            t=t->next;
        }
        tB=t;
        tA=headA;
    } else {
        struct ListNode *t=headA;
        for(i=0;i<dis;i++) {
            t=t->next;
        }
        tA=t;
        tB=headB;
    }
    
    while(tA!=tB) {
        tA=tA->next;
        tB=tB->next;
    }

    return tA;
}