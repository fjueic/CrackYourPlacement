class Solution {
  public:
    // Function to detect cycle in a directed graph.
    void TopoSort(queue<int> &q, vector<int> adj[], int &count,
                  unordered_map<int, int> &indegree) {
        while (!q.empty()) {
            int src = q.front();
            count++;
            q.pop();

            for (auto i : adj[src]) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    q.push(i);
                }
            }
        }
    }

    bool isCyclic(int V, vector<int> adj[]) {

        unordered_map<int, int> indegree;
        for (int i = 0; i < V; i++) {
            for (auto j : adj[i]) {
                indegree[j]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (!indegree[i]) {
                q.push(i);
            }
        }
        int count = 0;
        TopoSort(q, adj, count, indegree);
        if (count == V)
            return false;
        return true;
    }
};
