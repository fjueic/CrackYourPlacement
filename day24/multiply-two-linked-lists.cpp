class solution {
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        // code here
        long long a = 0, b = 0;
        int mod = 1e9 + 7;
        while (first) {
            a *= 10;
            a %= mod;
            a += first->data;
            first = first->next;
        }
        while (second) {
            b *= 10;
            b %= mod;
            b += second->data;
            second = second->next;
            ;
        }
        return (a * b) % mod;
    }
};
