class StockSpanner {
  public:
    StockSpanner() {}

    int next(int price) {
        // Stack to store pairs of (price, index)
        while (!st.empty() && st.top().first <= price) {
            st.pop();
        }

        int span = st.empty() ? index + 1 : index - st.top().second;
        st.push({price, index++});

        return span;
    }

  private:
    std::stack<std::pair<int, int>> st; // Stack of pairs (price, index)
    int index = 0; // To keep track of the index of the price
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
