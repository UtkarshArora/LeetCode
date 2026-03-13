class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<string>st;
        for(string s1 : tokens)
        {
            if(s1 == "+" || s1 == "-" || s1 == "*" || s1 == "/")
            {
                int num2 = stoi(st.top()); st.pop();
                int num1 = stoi(st.top()); st.pop();
                int ans;
                if(s1 == "+")
                {
                    ans = num1+num2;
                }
                else if(s1 == "-")
                {
                    ans = num1-num2;
                }
                else if(s1 == "*")
                {
                    ans = num1*num2;
                }
                else if(s1 == "/")
                {
                    ans = num1/num2;
                }
                st.push(to_string(ans));
            }
            else
            {
                st.push(s1);
            }
        }
        return stoi(st.top());
    }
};