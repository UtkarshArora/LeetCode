class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,bool>map1;
        for(int num : nums)
        {
            if(map1.find(num)!=map1.end())
                return true;
            map1[num] = true;
        }
        return false;
    }
};