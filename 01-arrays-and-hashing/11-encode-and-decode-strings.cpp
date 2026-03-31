class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for (auto& s: strs) {
            int n = s.size();
            res +=  to_string(n) + "#" + s;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;

        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            int length = stoi(s.substr(i, j-i));
            j++;
            string word = s.substr(j, length);
            res.push_back(word);
            i = j + length;
        }

        return res;
    }
};