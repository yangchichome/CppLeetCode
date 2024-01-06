class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {

        if (nums.empty()) {
            return 0;
        }

        int count = 1;
        int maxlen = 1;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                count++;
            } else {
                count = 1;
            }

            maxlen = max(maxlen, count);
        }

        return maxlen;
    }
};
