class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>set1;
        for(int num : nums)
        {
            if(set1.contains(num))
                return true;
            set1.insert(num);
        }
        return false;
    }
};