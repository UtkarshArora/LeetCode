class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        
        HashMap<String, List<String>>mp = new HashMap<>();
        for(String s : strs)
        {
            int[] counter = new int[26];
            for(char c : s.toCharArray())
            {
                counter[c-'a']++;
            }
            StringBuilder sb = new StringBuilder();
            for(int num : counter)
            {
                sb.append(num);
                sb.append('#');
            }
            String s2 = sb.toString();
            List<String>list1 = mp.getOrDefault(s2, new ArrayList<>());
            list1.add(s);
            mp.put(s2, list1);
        }
        List<List<String>>ans = new ArrayList<>();
        for(var e : mp.entrySet())
        {
            ans.add(e.getValue());
        }
        return ans;
    }
}