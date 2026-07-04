class Solution {
    public boolean containsDuplicate(int[] nums) {
        
        Map<Integer, Integer>map1 = new HashMap<>();
        for(int num : nums)
        {
            if(map1.containsKey(num))
            {
                return true;
            }
            map1.put(num, 1);
        }
        return false;
    }
}