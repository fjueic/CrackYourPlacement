class Solution {
public:
    TreeNode* bst (vector<int> nums,int s,int e){
        if(s>e)return NULL;
        int m=(s+e)/2;
        TreeNode* root=new TreeNode(nums[m]);
        root->left=bst(nums,s,m-1);
        root->right=bst(nums,m+1,e);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return bst(nums,0,nums.size()-1);
    }
};
