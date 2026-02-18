class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size() == 0)
        {
            return 0;
        }
        int longestConsecutive = 1;
        unordered_set<int>set1;
        for(int num : nums)
        {
            set1.insert(num);
        }
        for(int num : nums)
        {
            int currentNumber = num;
            int currentConsecutive = 1;
            if(set1.find(currentNumber-1) == set1.end())
            {
                while(set1.find(currentNumber+1)!=set1.end())
                {
                    currentConsecutive++;
                    currentNumber++;
                    set1.erase(currentNumber);
                }
                longestConsecutive = max(longestConsecutive, currentConsecutive);
            }
        }
        return longestConsecutive;
    }
};