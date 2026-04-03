class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (auto& token: tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int firstNum = st.top();
                st.pop();
                int secondNum = st.top();
                st.pop();
                int temp = 0;
                
                if (token == "+") {
                    temp = secondNum + firstNum;
                }
                else if (token == "-") {
                    temp = secondNum - firstNum;
                }
                else if (token == "*") {
                    temp = secondNum * firstNum;
                }
                else if (token == "/") {
                    temp = secondNum / firstNum;
                }

                st.push(temp);
            }
            else {
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};
