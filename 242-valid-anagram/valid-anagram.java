class Solution {
    public boolean isAnagram(String s, String t) {
        
        int[] arr = new int[26];
        
        for(char ch : s.toCharArray())
        {
            int index = (int)(ch) - (int)('a');
            arr[index]++;
        }
        for(char ch : t.toCharArray())
        {
            int index = (int)(ch) - (int)('a');
            arr[index]--;
        }
        for(int i = 0 ; i < 26 ; i++)
        {
            if(arr[i]!=0)
                return false;
        }
        return true;
    }
}