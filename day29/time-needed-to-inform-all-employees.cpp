class Solution {
  public:
    int dfs(vector<vector<int>> &adj, vector<int> &informTime, int u) {
        int maxTime = 0;
        for (int v : adj[u]) {
            maxTime = max(maxTime, dfs(adj, informTime, v));
        }
        return maxTime + informTime[u];
    }
    int numOfMinutes(int n, int headID, vector<int> &manager,
                     vector<int> &informTime) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            if (manager[i] != -1) {
                adj[manager[i]].push_back(i);
            }
        }
        return dfs(adj, informTime, headID);
    }
};
