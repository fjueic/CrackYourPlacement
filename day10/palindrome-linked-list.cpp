class Solution {
public:
    bool check(ListNode* head,ListNode*&h){
        if(head==NULL)return 1;
        bool a=check(head->next,h);
        if(!a || head->val!=h->val)return 0;
        h=h->next;
        return 1;
    }
    bool isPalindrome(ListNode* head) {
        return check(head,head);
    }
};
