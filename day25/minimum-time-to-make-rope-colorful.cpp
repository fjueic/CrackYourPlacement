class Solution {
  public:
    int minCost(string colors, vector<int> &neededTime) {
        int ans = 0;
        int n = colors.size();

        for (int i = 0; i < n;) {
            char cur = colors[i];
            int maxi = 0;
            int s = 0;

            while (i < n && colors[i] == cur) {
                s += neededTime[i];
                maxi = max(maxi, neededTime[i]);
                i++;
            }

            ans += (s - maxi);
        }

        return ans;
    }
};
