class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<vector<int>> result;
        vector<int> partial;
        sort(nums.begin(), nums.end());
        dfs(nums, 0, partial, result);

        return result;
    }

private:
    void dfs(const vector<int>& arr, int startIdx, vector<int>& partial, vector<vector<int>>& result) {
        // if (startIdx == arr.size()) {
        result.push_back(partial);
        //     return;
        // }
        for (int i = startIdx; i < arr.size(); i++) {
            if (i > startIdx && arr[i] == arr[i - 1]) {
                continue;
            }
            partial.push_back(arr[i]);
            dfs(arr, i+1, partial, result);
            partial.pop_back();
        }
    }
};
