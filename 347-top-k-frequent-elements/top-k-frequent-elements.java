class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        
        //store numbers and their freq in HashMap
        HashMap<Integer, Integer>map1 = new HashMap<>();
        for(int num : nums)
        {
            map1.put(num, map1.getOrDefault(num,0) + 1);
        }

        //store pair of <freq, number> in Priority Queue
        PriorityQueue<int[]>pq = new PriorityQueue<>((a,b) -> a[0] - b[0]);
        for(var e : map1.entrySet())
        {
            int[] arr = new int[2];
            arr[0] = e.getValue(); arr[1] = e.getKey();
            pq.offer(arr);
            if(pq.size() > k)
                pq.poll();
        }
        
        int[] ans = new int[k]; 
        int index = 0;
        // extracting from pq and pushing
        while(pq.size() > 0)
        {
            int[] arr = pq.poll();
            ans[index]= arr[1];
            index++;
        }
        return ans;
    }
}