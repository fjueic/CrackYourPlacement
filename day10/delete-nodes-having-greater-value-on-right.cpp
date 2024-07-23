class Solution
{
    Node * rev(Node*a){
        Node *pre=nullptr;
        Node *nex;
        while(a){
            nex=a->next;
            a->next=pre;
            pre=a;
            a=nex;
        }
        return pre;
    }
    public:
    Node *compute(Node *head)
    {
        // your code goes here
        Node *t=rev(head);
        head=t;
        int maxi=t->data;
        while(t->next){
            if(t->next->data<maxi){
                Node *d=t->next;
                t->next=t->next->next;
                delete d;
            }else{
                maxi=max(maxi,t->next->data);
                t=t->next;
            }
        }
        return rev(head);
    }
    
};
