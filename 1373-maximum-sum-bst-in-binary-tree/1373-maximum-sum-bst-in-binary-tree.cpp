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
    int ans = 0;

    struct Info {
        int sum;
        int minVal;
        int maxVal;
        bool isBST;
    };

    Info solve(TreeNode* root) {

        if (root == nullptr) {
            return {0, INT_MAX, INT_MIN, true};
        }

        Info left = solve(root->left);
        Info right = solve(root->right);

        if (left.isBST && right.isBST &&
            left.maxVal < root->val &&
            root->val < right.minVal) {

            int sum = left.sum + right.sum + root->val;

            ans = max(ans, sum);

            return {
                sum,
                min(root->val, left.minVal),
                max(root->val, right.maxVal),
                true
            };
        }

        return {0, 0, 0, false};
    }

    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};