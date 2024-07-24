class Solution {
public:
    ListNode* rev(ListNode * a){
        ListNode* pre=nullptr;
        ListNode * nex;
        while(a){
            nex=a->next;
            a->next=pre;
            pre=a;
            a=nex;
        }
        return pre;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=rev(l1);
        l2=rev(l2);
        int c= 0;
        ListNode* a=l1,*b=l2;
        while(l1 && l2){
            int t=l1->val+l2->val+c;
            c=t/10;
            t%=10;
            l1->val=t;
            l2->val=t;
            l1=l1->next;
            l2=l2->next;
        }
        if(c==0)return rev(l1?a:b);
        if(!l1&&!l2){
            l1=a;
            while(l1->next){
                l1=l1->next;
            }
            l1->next=new ListNode(1);
            return rev(a);
        }
        if(l1){
            while(l1->next && l1->val==9){
                l1->val=0;
                l1=l1->next;
            }
            if(l1->next){
                l1->val++;
            }else{
                if(l1->val==9){
                    l1->val=0;
                    l1->next=new ListNode(1);
                }else l1->val++;
            }
            return rev(a);
        }else{
            while(l2->next && l2->val==9){
                l2->val=0;
                l2=l2->next;
            }
            if(l2->next){
                l2->val++;
            }else{
                if(l2->val==9){
                    l2->val=0;
                    l2->next=new ListNode(1);
                }else l2->val++;
            }
            return rev(b);
        }
    }
};
