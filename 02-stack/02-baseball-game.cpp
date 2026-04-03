class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;

        for (auto& op: operations) {
            if (op == "C") {
                st.pop();
            }
            else if (op == "D") {
                st.push(st.top() * 2);
            }
            else if (op == "+") {
                int firstEl = st.top();
                st.pop();
                int secondEl = st.top();
                st.pop();
                st.push(secondEl);
                st.push(firstEl);
                st.push(firstEl + secondEl);
            }
            else {
                st.push(stoi(op));
            }
        }

        int sum = 0;
        while (!st.empty()) {
            sum += st.top();
            st.pop();
        }

        return sum;
    }
};
