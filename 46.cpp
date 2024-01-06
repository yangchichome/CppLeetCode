class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> result;
        if (nums.empty()) return result;

        vector<int> partial;
        sort(nums.begin(), nums.end());
        vector<bool> isVisited(nums.size(), false);
        dfs(nums, isVisited, partial, result);

        return result;
    }

private:
    void dfs(const vector<int>& arr, vector<bool>& isVisited, vector<int>& partial, vector<vector<int>>& result) {
        if (partial.size() == arr.size()) {
            result.push_back(partial);
            return;
        }

        for (int i = 0; i < arr.size(); ++i) {
            if (isVisited[i]) {
                continue;
            }
            // if (i > 0 && arr[i] == arr[i - 1] && !isVisited[i - 1]) {
            //     continue;
            // }

            partial.push_back(arr[i]);
            isVisited[i] = true;
            dfs(arr, isVisited, partial, result);
            isVisited[i] = false;
            partial.pop_back();
        }
    }
};