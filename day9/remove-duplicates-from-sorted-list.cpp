class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)return head;
        ListNode * t=head;
        while(t->next){
            if(t->val==t->next->val){
                t->next=t->next->next;
            }else{
                t=t->next;
            }
        }
        return head;
    }
};
