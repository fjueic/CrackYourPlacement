class Solution {
public:
    int length(Node* a){
        Node *t=a;
        int ans=0;
        while(t){
            ans++;
            t=t->next;
        }
        return ans;
    }
    Node * reverse(Node* a){
        Node * pre=nullptr;
        Node * nex;
        while(a){
            nex=a->next;
            a->next=pre;
            pre=a;
            a=nex;
        }
        return pre;
    }
    Node* subLinkedList(Node* head1, Node* head2) {
        // Your implementation of subLinkedList goes here
        // Make sure to return the head of the resulting linked list
        while(head1 && head1->data==0)head1=head1->next;
        while(head2 && head2->data==0)head2=head2->next;
        if(!head1 && !head2)return new Node(0);
        if(!head1 || !head2)return head1?head1 : head2;
        
        int x= length(head1);
        int y=length(head2);
        if(x<y){
            swap(head1,head2);
            swap(x,y);
        }
        Node *h1=head1,*h2=head2;
        if(x==y){
            while(h1 && h1->data==h2->data){
                h1=h1->next;
                h2=h2->next;
            }
            if(!h1)return new Node(0);
            if(h1->data<h2->data){
                swap(head1,head2);
            }
        }
        
        head1 = reverse(head1);
        head2 = reverse(head2);
        h1=head1;h2=head2;
        int c=0;
        while( head1){
            int a=head1->data;
            int b=head2?head2->data:0;
            head1->data=a-b+c;
            if(a-b+c<0){
                head1->data+=10;
                c=-1;
            }else{
                c=0;
            }
            head1=head1->next;
            if(head2)head2=head2->next;
        }
        head1=reverse(h1);
        while(head1 && head1->data==0)head1=head1->next;

        return head1;
    }
};
