class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); ++i) {
            int tmp = target - nums[i];
            if (map.find(tmp) != map.end()) {
                return {map[tmp], i};
            }

            if (map.find(nums[i]) == map.end()) {
                map[nums[i]] = i;
            }
        }

        return {-1, -1};
    }
};