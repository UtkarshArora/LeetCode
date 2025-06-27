class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for (char ch : s) {

            cout << "ch:c" << ch << endl;

            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
                cout << "pushed in the stack, ch:" << ch << endl;
            } else {
                if (st.empty())
                    return false;
                else if ((ch == ')' && st.top() != '(') ||
                         (ch == ']' && st.top() != '[') ||
                         (ch == '}' && st.top() != '{')) {
                    return false;
                } else
                    st.pop();
            }
        }
        return st.empty();
    }
};