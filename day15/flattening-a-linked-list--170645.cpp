class Solution {
public:
    Node* merge(Node *l1,Node*l2){
        if(!l1)return l2;
        if(!l2)return l1;
        Node *ans=new Node(-1);
        Node * t=ans;
        while(l1 && l2){
            if(l1->data<l2->data){
                ans->bottom=l1;
                l1=l1->bottom;
            }else{
                ans->bottom=l2;
                l2=l2->bottom;
            }
            ans=ans->bottom;
        }
        if(!l1 && !l2)return t->bottom;
        if(!l1){
            ans->bottom=l2;
        }else{
            ans->bottom=l1;
        }
        return t->bottom;
    }
    Node *flatten(Node *root)
    {
        // Your code here
        Node * ans =root;
        root=root->next;
        while(root){
            ans=merge(root,ans);
            root=root->next;
        }
        return ans;
    }
};
