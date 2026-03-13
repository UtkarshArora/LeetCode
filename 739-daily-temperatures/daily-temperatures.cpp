class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<pair<int, int>> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top().first <= temperatures[i]) {
                st.pop();
            }
            if (!st.empty()) {
                int count = st.top().second - i;
                ans[i] = count;
            }
            st.push({temperatures[i], i});
        }
        return ans;
    }
};