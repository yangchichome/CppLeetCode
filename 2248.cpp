class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> count(1001, 0);

        for (const auto& row : nums) {
            for (int num : row) {
                count[num]++;
            }
        }

        vector<int> result;
        for (int i = 1; i < 1001; ++i) {
            if (count[i] == nums.size()) {
                result.push_back(i);
            }
        }

        return result;
    }
};
