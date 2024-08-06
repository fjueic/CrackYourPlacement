class Solution {
  public:
    void solve(int i, vector<int> &a, vector<vector<int>> &ans) {
        if (i >= a.size()) {
            ans.push_back(a);
        }
        unordered_set<int> s;
        for (int j = i; j < a.size(); j++) {
            if (s.find(a[j]) != s.end())
                continue;
            s.insert(a[j]);
            swap(a[j], a[i]);
            solve(i + 1, a, ans);
            swap(a[j], a[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        vector<vector<int>> ans;
        solve(0, nums, ans);
        return ans;
    }
};
