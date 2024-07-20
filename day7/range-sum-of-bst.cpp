class Solution {
public:
    void solve(TreeNode* r, int l, int h,int &ans){
        if(!r)return;
        if(r->val<=h &&r->val>=l)ans+=r->val;
        if(r->val>l)solve(r->left,l,h,ans);
        if(r->val<h)solve(r->right,l,h,ans);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans=0;
        solve(root,low,high,ans);
        return ans;
    }
};
