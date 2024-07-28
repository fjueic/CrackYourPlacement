class Solution {
public:
    ListNode* reverse(ListNode * a){
        ListNode *p=nullptr,*n;
        while(a){
            n=a->next;
            a->next=p;
            p=a;
            a=n;
        }
        return p;
    }
    void reorderList(ListNode* head) {
        ListNode * s=head,*f=head;
        while(f && f->next){
            s=s->next;
            f=f->next->next;
        }
        f=reverse(s);
        s=head;
        while(true){
            if(!f || !f->next || s==f)break;

            ListNode *snex=s->next,*fnex=f->next;
            s->next=f;
            f->next=snex;
            f=fnex;
            s=snex;
        }
    }
};
