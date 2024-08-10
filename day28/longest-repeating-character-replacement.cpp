class Solution {
  public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        int i = 0;
        int j = 0;
        int n = s.size();
        int maxf = 0;
        vector<int> freq(26, 0);
        while (j < n) {
            freq[s[j] - 'A']++;
            maxf = max(maxf, freq[s[j] - 'A']);
            if (j - i + 1 - maxf > k) {
                freq[s[i] - 'A']--;
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};
