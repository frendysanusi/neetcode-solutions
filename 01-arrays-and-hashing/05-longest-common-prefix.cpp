class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int m = strs.size();
        int n = strs[0].length();
        
        string res;
        for (int j = 0; j < n; j++) {
            char pointer = strs[0][j];
            for (int i = 1; i < m; i++) {
                if (j >= strs[i].size() || strs[i][j] != pointer) {
                    return res;
                }
            }
            res += pointer;
        }
        return res;
    }
};