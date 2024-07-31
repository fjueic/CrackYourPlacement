class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        queue<int>q;
        q.push(0);
        vector<bool> vis(V,0);
        vis[0]=1;
        while(!q.empty()){
            int t=q.front();q.pop();
            ans.push_back(t);
            for(int i:adj[t]){
                if(!vis[i]){
                    vis[i]=1;
                    q.push(i);
                }
            }
        }
        return ans;
    }
};
