class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int longestConsecutive = 0;
        unordered_set<int>set1;
        for(int num : nums)
        {
            set1.insert(num);
        }
        for(int num : nums)
        {
            if(set1.find(num-1) == set1.end())
            {
                int currentNumber = num;
                int currentConsecutive = 1;
                while(set1.count(currentNumber+1))
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