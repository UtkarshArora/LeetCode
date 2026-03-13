class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int n = temperatures.size();
        vector<int>ans(n, 0);
        stack<pair<int,int>>st;
        ans[n-1] = 0;
        for(int i = n-1 ; i >=0 ; i--)
        {
            int count = 0;
            if(!st.empty() && st.top().first > temperatures[i])
            {
                
                count = (st.top().second - i);
            }
            else
            {
                while(!st.empty() && st.top().first <= temperatures[i])
                {
                    st.pop();
                }
                if(!st.empty())
                {
                    pair<int,int>p1 = st.top();
                    count = p1.second - i;
                }
            }
            ans[i] = count;
            st.push({temperatures[i], i});
        }
        return ans;
    }
};