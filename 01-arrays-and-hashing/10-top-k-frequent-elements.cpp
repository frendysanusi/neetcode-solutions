class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numFreq;
        for (int num: nums) {
            numFreq[num]++;
        }

        int n = nums.size();
        vector<vector<int>> cnt(n+1);
        for (auto& [num, freq]: numFreq) {
            cnt[freq].push_back(num);
        }

        vector<int> res;
        for (int i = n; i > 0 && res.size() < k; i--) {
            for (int num: cnt[i]) {
                res.push_back(num);
                if (res.size() == k) {
                    break;
                }
            }
        }

        return res;
    }
};