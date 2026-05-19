class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size() == 0)
            return 0;
        
        unordered_set<int>set1;
        for(int num : nums)
        {
            set1.insert(num);
        }
        int cons = 1;
        int maxCons = 1;
        for(int num : set1)
        {
            if(set1.find(num-1)==set1.end())
            {
                while(set1.find(num+1)!=set1.end())
                {
                    num++;
                    cons++;
                    maxCons = max(cons, maxCons);
                }
                cons = 1;
            }
        }
        return maxCons;
    }
};