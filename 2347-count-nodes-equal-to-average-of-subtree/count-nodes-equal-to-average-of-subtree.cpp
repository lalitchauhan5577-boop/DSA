class Solution {
public:
    int ans = 0;

    pair<int, int> dfs(TreeNode* root) {
        if (root == nullptr)
            return {0, 0};

        // Get sum and count of left subtree
        auto left = dfs(root->left);

        // Get sum and count of right subtree
        auto right = dfs(root->right);

        // Calculate sum of current subtree
        int sum = left.first + right.first + root->val;

        // Calculate number of nodes in current subtree
        int count = left.second + right.second + 1;

        // Check average
        if (sum / count == root->val)
            ans++;

        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};