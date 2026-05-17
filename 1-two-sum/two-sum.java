class Solution {
    public int[] twoSum(int[] nums, int target) {

        HashMap<Integer, Integer>map1 = new HashMap();
        for(int i = 0 ; i < nums.length ; i++)
        {
            int complement = target - nums[i];
            if(map1.containsKey(complement))
            {
                int[] ans = new int[2];
                int index2 = map1.get(complement);
                ans[0] = i;
                ans[1] = index2;
                return ans;
            }
            else
                map1.put(nums[i], i);
        }
        int[] ans = new int[2];
        ans[0] = -1; ans[1] = -1;
        return ans;
    }
}