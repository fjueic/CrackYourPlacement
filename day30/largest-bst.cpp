class Solution {
  public:
    struct Info {
        int size;
        int max_val;
        int min_val;
        int largest_bst_size;
        bool is_bst;
    };

    Info largestBstHelper(Node *root) {
        if (root == NULL) {
            return {0, INT_MIN, INT_MAX, 0, true};
        }

        Info left = largestBstHelper(root->left);
        Info right = largestBstHelper(root->right);

        Info curr;
        curr.size = 1 + left.size + right.size;
        if (left.is_bst && right.is_bst && root->data > left.max_val &&
            root->data < right.min_val) {
            curr.min_val = min(root->data, left.min_val);
            curr.max_val = max(root->data, right.max_val);
            curr.largest_bst_size = curr.size;
            curr.is_bst = true;
        } else {
            curr.largest_bst_size =
                max(left.largest_bst_size, right.largest_bst_size);
            curr.is_bst = false;
        }

        return curr;
    }

    int largestBst(Node *root) {
        return largestBstHelper(root).largest_bst_size;
    }
};
