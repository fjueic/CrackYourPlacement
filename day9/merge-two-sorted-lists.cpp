class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans=new ListNode();
        ListNode* t=ans;
        while(list1 || list2){
            if(!list1){
                t->next=list2;
                break;
            }
            if(!list2){
                t->next=list1;
                break;
            }
            if(list1->val<list2->val){
                t->next=list1;
                list1=list1->next;
            }else{
                t->next=list2;
                list2=list2->next;
            }
            t=t->next;
        }
        return ans->next;
    }
};
