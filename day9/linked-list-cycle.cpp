class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head)return 0;
        ListNode* s=head;
        ListNode*f=head->next;
        while(f &&f->next){
            if(f==s)return 1;
            f=f->next->next;
            s=s->next;
        }
        return 0;
    }
};
