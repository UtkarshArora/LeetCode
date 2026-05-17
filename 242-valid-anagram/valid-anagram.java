class Solution {
    public boolean isAnagram(String s, String t) {
        
        if(s.length()!=t.length())
            return false;
        
        HashMap<Character, Integer>sCount = new HashMap<>();
        HashMap<Character, Integer>tCount = new HashMap<>();

        for(int i = 0 ; i < s.length() ; i++)
        {
            char ch1 = s.charAt(i); 
            char ch2 = t.charAt(i);
            sCount.put(ch1, 1 + sCount.getOrDefault(ch1, 0));
            tCount.put(ch2, 1 + tCount.getOrDefault(ch2, 0));
        }

        return sCount.equals(tCount);
    }
}