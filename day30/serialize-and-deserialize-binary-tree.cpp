#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
  public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        string ans;
        if (!root)
            return ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *t = q.front();
            q.pop();
            if (!t) {
                ans += " n";
                continue;
            }
            ans += " " + to_string(t->val);
            q.push(t->left);
            q.push(t->right);
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {}
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
