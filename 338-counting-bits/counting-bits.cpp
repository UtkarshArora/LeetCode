class Solution {
public:

    int countOnes(int num)
    {
        int digit = 1;
        int count = 0;
        while(num)
        {
            count = count + (digit & num);
            num = num >> 1;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int>ans(n+1);
        for(int i = 0 ; i <=n ; i++)
        {
            ans[i] = countOnes(i);
        }
        return ans;
    }
};