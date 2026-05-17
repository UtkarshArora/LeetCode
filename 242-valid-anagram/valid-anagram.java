class Solution {
    public boolean isAnagram(String s, String t) {
        
        if(s.length()!=t.length())
            return false;
        
        HashMap<Character, Integer>sCount = new HashMap<>();
        HashMap<Character, Integer>tCount = new HashMap<>();
        int[] charCounts = new int[26];

        for(int i = 0 ; i < s.length() ; i++)
        {
            int index1 = s.charAt(i) - 'a'; 
            int index2 = t.charAt(i) - 'a';
            charCounts[index1]++;
            charCounts[index2]--;
        }

        for(int i = 0 ; i < 26 ; i++)
        {
            if(charCounts[i]!=0)
                return false;
        }
        return true;
    }
}