class Solution {
    public boolean isValid(String s) {
        
        Stack<Character>st = new Stack<>();
        for(char ch : s.toCharArray())
        {
            if(ch == '(' || ch == '{' || ch == '[')
                st.push(ch);
            else if(st.isEmpty())
                return false;
            else{
                if(!isPair(ch, st.peek()))
                {
                    return false;
                }
                st.pop();
            }
        }
        return st.isEmpty();
    }
    private boolean isPair(char last, char cur)
    {
        return (last == ')' && cur == '(') ||   
                 (last == '}' && cur == '{') || 
                 (last == ']' && cur == '[') ;
    }
}