class Solution {
  public:
    int maxDistance(vector<vector<int>> &grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        vector<vector<int>> dist(n, vector<int>(n, -1));
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        if (q.size() == 0 || q.size() == n * n)
            return -1;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto d : dir) {
                int nx = x + d[0];
                int ny = y + d[1];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n ||
                    dist[nx][ny] != -1)
                    continue;

                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, dist[i][j]);
            }
        }

        return ans;
    }
};
