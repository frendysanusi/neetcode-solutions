class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int largestArea = 0;
        vector<pair<int, int>> st;

        for (int i = 0; i < heights.size(); i++) {
            if (st.size() == 0) {
                st.push_back({i, heights[i]});
            }
            else {
                int startIdx = i;
                while (st.size() != 0 && st.back().second > heights[i]) {
                    startIdx = st.back().first;
                    int currArea = st.back().second * (i - startIdx);
                    largestArea = max(currArea, largestArea);
                    st.pop_back();
                }
                st.push_back({startIdx, heights[i]});
            }
        }

        for (int i = 0; i < st.size(); i++) {
            int currArea = st[i].second * (heights.size() - st[i].first);
            largestArea = max(currArea, largestArea);
        }

        return largestArea;
    }
};
