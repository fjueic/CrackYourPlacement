class Solution {
public:
    const static int mod = 1e9 + 7;
    vector<vector<int>> memo;

    int solve(int n, int place) {
        if (n == 1)
            return 1;
        if (memo[n][place] != -1)
            return memo[n][place];

        int ans = 0;
        switch (place) {
        case 1:
            ans = (solve(n - 1, 6) + solve(n - 1, 8)) % mod;
            break;
        case 2:
            ans = (solve(n - 1, 7) + solve(n - 1, 9)) % mod;
            break;
        case 3:
            ans = (solve(n - 1, 4) + solve(n - 1, 8)) % mod;
            break;
        case 4:
            ans = (solve(n - 1, 3) + solve(n - 1, 9)) % mod;
            ans = (ans + solve(n - 1, 0)) % mod;
            break;
        case 6:
            ans = (solve(n - 1, 1) + solve(n - 1, 7)) % mod;
            ans = (ans + solve(n - 1, 0)) % mod;
            break;
        case 7:
            ans = (solve(n - 1, 2) + solve(n - 1, 6)) % mod;
            break;
        case 8:
            ans = (solve(n - 1, 1) + solve(n - 1, 3)) % mod;
            break;
        case 9:
            ans = (solve(n - 1, 2) + solve(n - 1, 4)) % mod;
            break;
        case 0:
            ans = (solve(n - 1, 4) + solve(n - 1, 6)) % mod;
            break;
        }
        return memo[n][place] = ans;
    }

    int knightDialer(int n) {
        if (n == 1)
            return 10;
        memo.assign(n + 1, vector<int>(10, -1));
        int ans = 0;
        for (int i = 0; i <= 9; i++) {
            if (i == 5)
                continue;
            ans = (ans + solve(n, i)) % mod;
        }
        return ans;
    }
};

