class Solution {
public:
    bool solve(TreeNode* root,long long  min,long long max){
        if(!root)return 1;
        if(root->val<min || root->val>max)return 0;
        return solve(root->left,min,1LL*root->val-1)&&solve(root->right,1LL*root->val+1,max);
    }
    bool isValidBST(TreeNode* root) {
        return solve(root,INT_MIN,INT_MAX);
    }
};
