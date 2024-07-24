class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)return head;
        Node* h=head;
        while(h){
            Node * t=h->next;
            h->next=new Node(h->val);
            h->next->next=t;
            h=t;
        }
        h=head;
        while(h){
            if(!h->random || !h->random->next)h->next->random=NULL;
            else h->next->random=h->random->next;
            h=h->next->next;
        }
        h=head;
        Node * ans=h->next;
        while(h){
            Node *t=h->next;
            h->next=h->next->next;
            t->next=(h->next?t->next->next:NULL);
            h=h->next;
            t=t->next;
        }



        return ans;
    }
};
