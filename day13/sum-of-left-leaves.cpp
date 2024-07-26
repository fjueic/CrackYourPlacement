class Solution {
public:
    void solve(TreeNode*par,TreeNode*r,int &ans){
        if(!r)return;
        if(par && !r->left&&!r->right&&par->left==r)ans+=r->val;
        solve(r,r->left,ans);
        solve(r,r->right,ans);

    }
    int sumOfLeftLeaves(TreeNode* root) {
        int a=0;
        solve(NULL,root,a);
        return a;
    }
};
