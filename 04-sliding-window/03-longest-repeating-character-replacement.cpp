class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> charFreq(26, 0);
        int left = 0;
        int maxFreq = 0;
        int maxLength = 0;

        for (int right = 0; right < s.size(); right ++) {
            charFreq[s[right] - 'A'] ++;
            maxFreq = max(maxFreq, charFreq[s[right] - 'A']);

            while ((right - left + 1) - maxFreq > k) {
                charFreq[s[left] - 'A'] --;
                left ++;
            }

            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
