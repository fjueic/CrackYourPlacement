class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int x=0,y=0;
        ListNode *a=headA;
        ListNode *b=headB;
        while(headA){
            x++;
            headA=headA->next;
        }
        while(headB){
            y++;
            headB=headB->next;
        }
        int dif=abs(x-y);
        while(x<y){
            y--;
            b=b->next;
        }
        while(x>y){
            x--;
            a=a->next;
        }
        while(a!=b){
            if(!a ||!b)return NULL;
            a=a->next;
            b=b->next;
        }
        return a;
    }
};
