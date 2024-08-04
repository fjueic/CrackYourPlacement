class Solution {
  public:
    bool isDigit(char c) { return c >= '0' && c <= '9'; }
    string solve(string &s, int &i) {
        string res = "";
        while (i < s.length() && s[i] != ']') {
            if (!isdigit(s[i])) {
                res += s[i++];
            } else {
                int n = 0;
                while (i < s.length() && isdigit(s[i])) {
                    n = n * 10 + s[i++] - '0';
                }
                i++; // '['
                string t = solve(s, i);
                i++; // ']'
                while (n--) {
                    res += t;
                }
            }
        }
        return res;
    }
    string decodeString(string s) {
        int i = 0;
        return solve(s, i);
    }
};
