class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        int index = 0;
        int n = asteroids.size();
        int curr = 0;
        while(index < n)
        {
            if(asteroids[index] > 0)
                index++;
            else
            {
                curr = index;
                while(curr >= 1)
                {
                    int prevA = asteroids[curr-1];
                    int currA = asteroids[curr];
                    if(prevA * currA > 0)
                        break;
                    if(abs(prevA) > abs(currA))
                    {
                        asteroids[curr] = 0;
                        break;
                    }
                    else if(abs(prevA) == abs(currA))
                    {
                        asteroids[curr] = 0;
                        asteroids[curr-1] = 0;
                        break;
                    }
                    else
                    {
                        asteroids[curr-1] = currA;
                        asteroids[curr] = 0;
                        curr--;
                    }
                }
                index++;
            }
        }
        vector<int>ans;
        for(int i = 0 ; i < n ; i++)
        {
            if(asteroids[i]!=0)
                ans.push_back(asteroids[i]);
        }
        return ans;
        // vector<int>ans;
        // int curr = asteroids[0];
        // int n = asteroids.size();
        // for(int i = 1 ; i < n ; i++)
        // {
        //     if(curr == 0)
        //     {
        //         curr = asteroids[i];
        //         continue;
        //     }
        //     int nextA = asteroids[i];
        //     if((curr * nextA) > 0)
        //     {
        //         ans.push_back(curr);
        //         curr = nextA;
        //     }
        //     else if(curr > 0 && nextA < 0)
        //     {
        //         if(abs(curr) == abs(nextA))
        //         {
        //             curr = 0;
        //             i++;
        //         }
        //         else if(abs(curr) < abs(nextA))
        //         {
        //             curr = nextA;
        //         }
        //     }
        //     else
        //     {
        //         ans.push_back(curr);
        //         curr = nextA;
        //     }
        //     while(curr < 0)
        //     {
        //         int index = ans[ans.size()-1];
        //         if(abs(curr) > abs(ans[index]))
        //         {
        //             ans[index] = 0;
        //             index--;
        //         }
        //         else
        //         {
        //             abs(curr)
        //         }
        //     }
        // }
    }
};