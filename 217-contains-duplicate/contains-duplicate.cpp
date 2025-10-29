class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>s1;
        for(int num : nums)
        {
            if(s1.find(num)!=s1.end())
            {
                return true;
            }
            else
            {
                s1.insert(num);
            }
        }
        return false;
    }
};