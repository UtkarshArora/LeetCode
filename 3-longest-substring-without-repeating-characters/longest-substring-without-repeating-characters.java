class Solution {
    public int lengthOfLongestSubstring(String s) {

        int start = 0, end = 0;
        int maxlen = 0;
        HashMap<Character, Integer>mp = new HashMap<>();
        while(end < s.length())
        {
            char ch = s.charAt(end);
            if(mp.containsKey(ch))
            {
                int index = mp.get(ch);
                start = Math.max(start, index+1);
            }
            mp.put(ch, end);
            int len = end - start + 1;
            maxlen = Math.max(len, maxlen);
            end++;
        }
        return maxlen;
    }
}