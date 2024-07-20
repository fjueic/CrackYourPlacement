class Solution {
public:
    int depth(TreeNode* root,int &ans){
        if(root==NULL)return 0;
        int ld=depth(root->left,ans);
        int rd=depth(root->right,ans);
        ans=max(ans,ld+rd+1);
        return max(ld,rd)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        depth(root,ans);
        return ans-1;
    }
};
