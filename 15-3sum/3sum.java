class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        
        Arrays.sort(nums);
        int n = nums.length;
        List<List<Integer>>ans = new ArrayList<>();
        for(int i = 0 ; i < n ; i++)
        {
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            int start = i+1;
            int end = n-1;
            while(start < end)
            {
                int sum = nums[start] + nums[end] + nums[i];
                if(sum == 0)
                {
                    List<Integer>list1 = new ArrayList<>(List.of(nums[i], nums[start], nums[end]));
                    ans.add(list1);
                    while(start < end && nums[start] == nums[start+1])
                    {
                        start++;
                    }
                    start++;
                }
                else if(sum < 0)
                    start++;
                else
                    end--;
            }
        }
        return ans;
    }
}