class Solution {
    public boolean isValid(String s) {
        
        ArrayDeque<Character>st = new ArrayDeque<>();
        for(char ch : s.toCharArray())
        {
            if(ch == '(' || ch == '{' || ch == '[')
                st.push(ch);
            else if(st.size() == 0)
                return false;
            else{
                if(ch == ')')
                {
                    if(st.peek() == '(')
                        st.pop();
                    else
                        return false;
                }
                else if(ch == '}')
                {
                    if(st.peek() == '{')
                        st.pop();
                    else
                        return false;
                }
                else if(ch == ']')
                {
                    if(st.peek() == '[')
                        st.pop();
                    else
                        return false;
                }
            }
        }
        return st.size() == 0;
    }
}