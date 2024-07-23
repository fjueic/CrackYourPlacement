class Solution {
public:
    ListNode* reverseList(ListNode* a) {
        ListNode* pre=nullptr;
        ListNode* nex;
        while(a){
            nex=a->next;
            a->next=pre;
            pre=a;
            a=nex;
        }
        return pre;
    }
};
