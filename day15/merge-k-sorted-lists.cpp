class Solution {
public:
    struct comp{
        bool operator()(ListNode *a,ListNode*b){
            return a->val>b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,comp> h;
        for(ListNode* n:lists){
            if(n)h.push(n);
        }
        ListNode* ans=new ListNode(-1);
        ListNode*x=ans;
        while(!h.empty()){
            ListNode *t=h.top();
            h.pop();
            ans->next=t;
            ans=t;
            if( t->next)h.push(t->next);
        }
        return x->next;
    }
};
