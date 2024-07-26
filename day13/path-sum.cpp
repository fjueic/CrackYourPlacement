class Solution {
public:
    bool hasPathSum(TreeNode* root, int t) {
        if(!root)return 0;
        if(!root->left&&!root->right)return root->val==t;
        return hasPathSum(root->left,t-root->val) || 
               hasPathSum(root->right,t-root->val);
    }
};
