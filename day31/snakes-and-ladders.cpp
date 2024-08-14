class Solution {
  public:
    int snakesAndLadders(vector<vector<int>> &board) {
        int n = board.size();
        vector<int> flat;
        flat.push_back(0);
        bool leftToRight = true;
        for (int i = n - 1; i >= 0; i--) {
            if (leftToRight) {
                for (int j = 0; j < n; j++) {
                    flat.push_back(board[i][j]);
                }
            } else {
                for (int j = n - 1; j >= 0; j--) {
                    flat.push_back(board[i][j]);
                }
            }
            leftToRight = !leftToRight;
        }
        int steps = 0;
        queue<int> q;
        vector<bool> visited(n * n + 1, false);
        q.push(1);
        visited[1] = true;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int curr = q.front();
                q.pop();
                if (curr == n * n) {
                    return steps;
                }
                for (int j = 1; j <= 6; j++) {
                    int next = curr + j;
                    if (next <= n * n && !visited[next]) {
                        if (flat[next] != -1) {
                            q.push(flat[next]);
                            visited[flat[next]] = true;
                        } else {
                            q.push(next);
                            visited[next] = true;
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
