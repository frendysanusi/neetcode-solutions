class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> charFreqS1(26, 0);
        vector<int> charFreqS2(26, 0);
        int left = 0;

        for (char c: s1) {
            charFreqS1[c - 'a'] ++;
        }

        for (int right = 0; right < s2.size(); right ++) {
            charFreqS2[s2[right] - 'a'] ++;

            if (right - left + 1 > s1.size()) {
                charFreqS2[s2[left] - 'a'] --;
                left ++;
            }

            if (charFreqS1 == charFreqS2) {
                return true;
            }
        }

        return false;
    }
};
