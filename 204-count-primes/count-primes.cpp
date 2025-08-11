class Solution {
public:
    int countPrimes(int n) {
        
        int maxCount = floor(sqrt(n));
        vector<int>primeNums(n+1,1);
        int count = 0;
        for(int i = 2 ; i <=maxCount ; i++)
        {   
            if(primeNums[i] == 0)
                continue;
            for(int j = 2 ; (i*j)<=n ; j++)
            {
                int num = i*j;
                primeNums[num] = 0;
            }
        }
        for(int i = 2 ; i < n ; i++)
        {
            count += primeNums[i];
        }
        return count;
    }
};