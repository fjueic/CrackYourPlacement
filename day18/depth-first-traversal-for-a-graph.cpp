class Solution{
public:
    void GetDfs(vector<int> adj[], unordered_map<int, bool> &visited, vector<int> &ans, int src)    {
        ans.push_back(src);
        visited[src] = true;

        for (auto i : adj[src]){
            if (visited[i] == false){
                GetDfs(adj, visited, ans, i);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[])    {
        // Code here
        unordered_map<int, bool> visited;

        vector<int> ans;
        GetDfs(adj, visited, ans, 0);
        return ans;
    }
};
