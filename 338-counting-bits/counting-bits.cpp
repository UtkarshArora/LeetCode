class Solution {
public:

    int cB(int num)
    {
        int count = 0;
        while(num!=0)
        {
            count++;
            num = num & (num-1);
        }
        return count;
    }
    vector<int> countBits(int n) {
        
        vector<int>ans(n+1);
        
        for(int i = 0 ; i <= n ; i++)
        {
            int num = cB(i);
            ans[i] = num;
        }
        return ans;
    }
};