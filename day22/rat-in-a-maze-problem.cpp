class Solution {
  public:
    void rec(int i, int j, int n, vector<vector<int>> &m, vector<string> &ans,
             string path, vector<vector<bool>> &vis) {
        if (i == n - 1 && j == n - 1) {
            ans.push_back(path);
            return;
        }
        vis[i][j] = true;
        if (i - 1 >= 0 && m[i - 1][j] && !vis[i - 1][j]) {
            rec(i - 1, j, n, m, ans, path + "U", vis);
        }
        if (i + 1 < n && m[i + 1][j] && !vis[i + 1][j]) {
            rec(i + 1, j, n, m, ans, path + "D", vis);
        }
        if (j - 1 >= 0 && m[i][j - 1] && !vis[i][j - 1]) {
            rec(i, j - 1, n, m, ans, path + "L", vis);
        }
        if (j + 1 < n && m[i][j + 1] && !vis[i][j + 1]) {
            rec(i, j + 1, n, m, ans, path + "R", vis);
        }
        vis[i][j] = false;
    }

    vector<string> findPath(vector<vector<int>> &m) {
        // Your code goes
        int n = m.size();
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        vector<string> ans;
        if (m[0][0] == 0)
            return ans;
        rec(0, 0, n, m, ans, "", vis);
        return ans;
    }
};
