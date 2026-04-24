class Solution {
    public boolean containsDuplicate(int[] nums) {
        
        Set<Integer>set1 = new HashSet<>();
        for(int i = 0 ; i < nums.length ; i++)
        {
            int num = nums[i];
            if(set1.contains(num))
            {
                return true;
            }
            set1.add(num);
        }
        return false;
    }
}