
class Solution {
public:
    bool solve(TreeNode* a,TreeNode*b){
        if(!a && !b)return 1;
        if(!a || !b)return 0;
        if(a->val!=b->val)return 0;
        return solve(a->left,b->right) && solve(a->right,b->left);
    }
    bool isSymmetric(TreeNode* root) {
        return solve(root,root);
    }
};
