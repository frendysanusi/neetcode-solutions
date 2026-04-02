class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longestLength = 0;

        for (int num: numSet) {
            if (numSet.find(num - 1) == numSet.end()) {
                int currNum = num;
                int currLength = 1;

                while (numSet.find(currNum + 1) != numSet.end()) {
                    currNum ++;
                    currLength ++;
                }

                if (currLength > longestLength) {
                    longestLength = currLength;
                }
            }
        }

        return longestLength;
    }
};