class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        
        Arrays.sort(nums);
        int n = nums.length;
        List<List<Integer>>ans = new ArrayList<>();
        for(int i = 0 ; i < n ; i++)
        {
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            int num = nums[i];
            int target = -nums[i];
            int start = i+1;
            int end = n-1;
            while(start < end)
            {
                int sum = nums[start] + nums[end];
                if(sum == target)
                {
                    List<Integer>list1 = new ArrayList<>(List.of(nums[i], nums[start], nums[end]));
                    ans.add(list1);
                    while(start < end && nums[start] == nums[start+1])
                    {
                        start++;
                    }
                    while(start < end && nums[end] == nums[end-1])
                    {
                        end--;
                    }
                    start++;
                    end--;
                }
                else if(sum < target)
                    start++;
                else
                    end--;
            }
        }
        return ans;
    }
}