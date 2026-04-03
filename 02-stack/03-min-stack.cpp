class MinStack {
private:
    vector<pair<int, int>> st;

public:
    MinStack() {

    }
    
    void push(int val) {
        if (st.empty()) {
            st.push_back({val, val});
        }
        else {
            int currMin = min(val, getMin());
            st.push_back({val, currMin});
        }
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        return st.back().first;
    }
    
    int getMin() {
        return st.back().second;
    }
};
