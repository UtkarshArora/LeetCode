class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        
        HashMap<String, List<String>>mp = new HashMap<>();
        for(int i = 0 ; i < strs.length; i++)
        {
            String s1 = strs[i];
            int[] counter = new int[26];
            for(int j = 0 ; j < s1.length(); j++)
            {
                char ch = s1.charAt(j);
                int index = ch - 'a';
                counter[index]++;
            }
            StringBuilder sb = new StringBuilder();
            for(int k = 0 ; k < 26 ; k++)
            {
                if(counter[k] > 0)
                {
                    sb.append(counter[k]);
                    char ch = (char) (k + 'a');
                    sb.append(ch);
                }
            }
            String s2 = sb.toString();
            List<String>list1 = mp.getOrDefault(s2, new ArrayList<>());
            list1.add(s1);
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