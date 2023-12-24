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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;

        if (root == nullptr)
            return result;

        queue<TreeNode*> q;
        q.push(root);
        bool isReverse = false;

        while (!q.empty()) {
            vector<int> sublist;
            int s = q.size();
            for (int i = 0; i < s; i++) {
                TreeNode* node = q.front();
                q.pop();
                sublist.push_back(node->val);

                if (node->right != nullptr)
                    q.push(node->right);
                if (node->left != nullptr)
                    q.push(node->left);
            }

            if (!isReverse)
                reverse(sublist.begin(), sublist.end());

            isReverse = !isReverse;

            result.push_back(sublist);
        }

        return result;
    }
};