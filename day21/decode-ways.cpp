class Solution {
  public:
    int solve(string s, int i, vector<int> &dp) {
        if (i >= s.size())
            return 1;
        if (i == s.size() - 1)
            return s[i] != '0';
        if (s[i] == '0')
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int n1 = solve(s, i + 1, dp);
        int n2 = solve(s, i + 2, dp);
        if (s[i] > '2')
            return dp[i] = n1;
        if (s[i + 1] == '0' || (s[i] == '2' && s[i + 1] > '6'))
            return dp[i] = n2;
        return dp[i] = n1 + n2;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 1);
        dp[n - 1] = s[n - 1] != '0';
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] == '0')
                dp[i] = 0;
            else if (s[i] > '2') {
                dp[i] = dp[i + 1];
            } else if (s[i + 1] == '0' || (s[i] == '2' && s[i + 1] > '6')) {
                dp[i] = dp[i + 2];
            } else {
                dp[i] = dp[i + 1] + dp[i + 2];
            }
        }
        return dp[0];
    }
};
