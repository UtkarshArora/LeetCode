class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        int n = hand.size();
        if((n % groupSize)!= 0)
            return false;
        
        int numGroups = n /groupSize;

        sort(hand.begin(), hand.end());
        unordered_map<int,int>map1;
        int ans = 0;
        for(int i = 0 ; i < n ; i++)
        {
            map1[hand[i]]++;
        }
        for(int i = 0 ; i < n ; )
        {   
            int val = hand[i];
            int count = 0;
            for(int j = 0 ; j < groupSize; j++)
            {
                if(map1[val])
                {
                    map1[val]--;
                    count++;
                }
                else
                    break;
                val++;
            }
            if(count == groupSize)
                ans++;
            if(map1[val] == 0)
                i++;
        }
        return ans == numGroups;
    }
};