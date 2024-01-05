class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> result;
        vector<int> partial;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target, partial, result);
        return result;
    }

private:
    void dfs(const vector<int>& arr, int startIdx, int target, vector<int>& partial, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(partial);
        }

        for (int i = startIdx; i < arr.size(); i++) {
            int targetNew = target - arr[i];
            if (targetNew < 0) {
                break;
            }

            partial.push_back(arr[i]);
            dfs(arr, i, targetNew, partial, result);
            partial.pop_back();
        }
    }
};