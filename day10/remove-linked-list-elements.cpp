class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while(head && head->val==val){
            ListNode * t=head;
            head=head->next;
            delete t;
        }
        if(!head || !head->next)return head;
        ListNode*ans=head;
        while(head->next){
            if(head->next->val==val){
                ListNode * t=head->next;
                head->next=t->next;
                delete t;
            }else{
                head=head->next;
            }

        }
        return ans;
    }
};
