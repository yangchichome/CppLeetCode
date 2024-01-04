/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;

        if (root == nullptr) {
            return result;
        }

        queue<TreeNode*> queue;
        queue.push(root);

        while (!queue.empty()) {
            int levelSize = queue.size();
            vector<int> levelValues;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = queue.front();
                queue.pop();

                levelValues.push_back(node->val);

                if (node->left != nullptr) {
                    queue.push(node->left);
                }

                if (node->right != nullptr) {
                    queue.push(node->right);
                }
            }

            result.push_back(levelValues);
        }

        reverse(result.begin(), result.end());

        return result;
    }
};