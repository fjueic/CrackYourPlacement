class Solution{
public:
    int getCount(Node *root, int l, int h)
    {
      // your code goes here   
      if(!root)return 0;
      return (root->data>=l && root->data<=h)+getCount(root->left,l,h)+getCount(root->right,l,h);
    }
};
