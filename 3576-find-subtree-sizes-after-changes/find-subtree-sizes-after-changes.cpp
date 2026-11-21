
class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n);

        // Build original tree
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> ans(n, 1);

        // Stores the nearest ancestor for each character
        vector<int> last(26, -1);

        function<void(int)> dfs = [&](int u) {
            int c = s[u] - 'a';

            // Save previous node with same character
            int old = last[c];

            // Current node becomes the latest
            last[c] = u;

            // Process children
            for (int v : adj[u]) {
                dfs(v);
            }

            // Find the new parent
            int newParent = (old != -1) ? old : parent[u];

            // Add current subtree size to its new parent
            if (newParent != -1) {
                ans[newParent] += ans[u];
            }

            // Restore previous ancestor
            last[c] = old;
        };

        dfs(0);

        return ans;
    }
};
