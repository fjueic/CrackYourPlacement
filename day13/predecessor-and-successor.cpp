class Solution
{
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        if(!root)return;
        // Your code goes here
        if(root->key==key){
            if(root->left){
                pre=root->left;
                while(pre && pre->right)pre=pre->right;
            }
            if(root->right){
                suc=root->right;
                while(suc && suc->left)suc=suc->left;
            }
        }else{
            if(root->key>key){
                if(!suc || suc->key>root->key)suc=root;
                findPreSuc(root->left,pre,suc,key);
            }else{
                if(!pre || pre->key<root->key)pre=root;
                findPreSuc(root->right,pre,suc,key);
            }
        }
    }
};
