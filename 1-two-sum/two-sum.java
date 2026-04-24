class Solution {
    public int[] twoSum(int[] nums, int target) {

        HashMap<Integer, Integer>mp = new HashMap<>();
        int[] ans = new int[2];
        for(int i = 0 ; i < nums.length; i++)
        {
            int num = nums[i];
            int diff = target - num;
            if(mp.containsKey(diff))
            {
                int index1 = mp.get(diff);
                ans[0] = index1;
                ans[1] = i;
                return ans;
            }
            else
            {
                mp.put(num, i);
            }
        }
        return ans;
    }
}