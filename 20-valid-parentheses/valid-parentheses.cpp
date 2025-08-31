class Solution {
public:
    bool isValid(string s) {

        stack<char>st;
        for(char ch : s)
        {
            if(ch == '(' || ch == '[' || ch == '{')
                st.push(ch);
            else if(!st.empty()){
                if(st.top() == '(' && ch!=')')
                    return false;
                if(st.top() == '[' && ch!=']')
                    return false;
                if(st.top() == '{' && ch!='}')
                    return false;
                st.pop();
            }
            else
                return false;
        }
        return st.empty();
    }
};