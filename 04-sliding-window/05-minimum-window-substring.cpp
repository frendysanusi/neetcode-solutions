class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> windowMap, needMap;
        int left = 0;
        int startIdx = -1;
        int shortestLen = INT_MAX;

        for (char c: t) {
            needMap[c] ++;
        }

        int have = 0;
        int need = needMap.size();

        for (int right = 0; right < s.size(); right ++) {
            windowMap[s[right]] ++;
            if (windowMap[s[right]] == needMap[s[right]]) {
                have ++;
            }

            while (have == need) {
                if (right - left + 1 < shortestLen) {
                    shortestLen = right - left + 1;
                    startIdx = left;
                }
                if (windowMap[s[left]] == needMap[s[left]]) {
                    have --;
                }
                windowMap[s[left]] --;
                left ++;
            }
        }

        if (startIdx == -1) {
            return "";
        }

        return s.substr(startIdx, shortestLen);
    }
};
