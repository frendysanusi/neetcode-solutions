class Solution {
public:
    bool isAnagram(string s, string t) {
        int s_length = s.length();
        int t_length = t.length();

        if (s_length != t_length) {
            return false;
        }

        vector<int> freq(26, 0);
        for (int i = 0; i < s_length; i++) {
            freq[s[i] - 'a'] --;
            freq[t[i] - 'a'] ++;
        }

        for (int cnt: freq) {
            if (cnt != 0) {
                return false;
            }
        }

        return true;
    }
};
