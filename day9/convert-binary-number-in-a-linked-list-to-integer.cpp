class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans=0;
        ListNode * t=head;
        while(head){
            ans|=head->val;
            ans<<=1;
            head=head->next;
        }
        return ans>>1;
    }
};
