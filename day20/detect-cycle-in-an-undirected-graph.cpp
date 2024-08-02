class Solution
{
public:
    void isCycleBYdfs(vector<int> adj[], unordered_map<int, bool> &visited, unordered_map<int, int> &track, bool &ans, int src)
    {

        for (auto it : adj[src])
        {
            if (visited[it] == true && track[src] != it)
                ans = true;
            else if (visited[it] == false)
            {
                track[it] = src;
                visited[it] = true;
                isCycleBYdfs(adj, visited, track, ans, it);
            }
        }
    }

    bool isCycle(int V, vector<int> adj[])
    {
        // Code here
        bool ans = false;
        unordered_map<int, int> track;
        unordered_map<int, bool> visited;
        for (int i = 0; i < V; i++)
        {
            if (visited[i] == false)
            {
                visited[i] = true;
                track[i] = -1;
                isCycleBYdfs(adj, visited, track, ans, i);
                if (ans == true)
                    return ans;
            }
        }

        return ans;
    }
};
