class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* l=new ListNode(-1);
        ListNode* g=new ListNode(-1);
        ListNode* l1=l,*g1=g;
        while(head){
            if(head->val<x){
                l->next=head;
                l=l->next;
            }else{
                g->next=head;
                g=g->next;
            }
            head=head->next;
        }
        g->next=nullptr;
        l->next=g1->next;
        return l1->next;
    }
};
