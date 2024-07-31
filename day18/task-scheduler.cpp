class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char task : tasks) {
            freq[task - 'A']++;
        }
        sort(freq.begin(), freq.end(), greater<int>());
        int maxFreq = freq[0] - 1;
        int idleSlots = maxFreq * n;
        for (int i = 1; i < 26; i++) {
            idleSlots -= min(maxFreq, freq[i]);
        }
        return idleSlots > 0 ? idleSlots + tasks.size() : tasks.size();
    }
};
