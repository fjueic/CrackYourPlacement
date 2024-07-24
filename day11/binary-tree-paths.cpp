class Solution {
public:
    void solve(vector<string> &ans,string cur,TreeNode* root){
        if(!root)return;
        if(!root->left && !root->right){
            ans.push_back(cur+"->"+to_string(root->val));
            return;
        }
        cur+="->"+to_string(root->val);
        solve(ans,cur,root->left);
        solve(ans,cur,root->right);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string cur=to_string(root->val);
        vector<string> ans;
        solve(ans,cur,root->left);
        solve(ans,cur,root->right);
        if(ans.size()==0)ans.push_back(cur);
        return ans;
    }
};
