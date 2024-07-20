
void solve(int &i,int n,int pre[],char preLN[],Node* par){
    if(i==n)return;
    

    par->left=new Node(pre[i]);
    i++;
    if(preLN[i-1]=='N'){
        solve(i,n,pre,preLN,par->left);
    }
    par->right=new Node(pre[i]);
    i++;
    if(preLN[i-1]=='N'){
        solve(i,n,pre,preLN,par->right);
    }
}
struct Node *constructTree(int n, int pre[], char preLN[])
{
    // Code here
    Node * r= new Node(pre[0]);
    int i=1;
    solve(i,n,pre,preLN,r);
    return r;
}
