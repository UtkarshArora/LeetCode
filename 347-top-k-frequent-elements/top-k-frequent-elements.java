class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        
        PriorityQueue<Pair<Integer,Integer>>freq = new PriorityQueue<>((a,b) -> {return b.getKey() - a.getKey();});
        HashMap<Integer,Integer>mp = new HashMap<>();
        int[] ans = new int[k];
        for(int num : nums)
        {
            if(mp.containsKey(num)){
                int val = mp.get(num);
                mp.put(num, val+1);
            }
            else{
                mp.put(num,1);
            }
        }

        for(int p : mp.keySet())
        {
            int val = mp.get(p);
            Pair<Integer,Integer> pair1 = new Pair(val, p);
            freq.add(pair1);
        }
        int count = 0;
        while(count < k)
        {
            Pair<Integer, Integer> p = freq.poll();
            ans[count]= p.getValue();
            count++;
        }
        return ans;
    }
}