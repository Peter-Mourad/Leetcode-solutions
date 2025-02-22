class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        stack<pair<TreeNode*, int>> st; // Stores (TreeNode, depth)
        int i = 0, n = traversal.size();

        while (i < n) {
            int depth = 0;
            while (i < n && traversal[i] == '-') {
                depth++;
                i++;
            }
            
            int value = 0;
            while (i < n && isdigit(traversal[i])) {
                value = value * 10 + (traversal[i] - '0');
                i++;
            }

            TreeNode* node = new TreeNode(value);

            // Find correct parent by popping stack until matching depth
            while (!st.empty() && st.top().second >= depth) {
                st.pop();
            }

            if (!st.empty()) {
                TreeNode* parent = st.top().first;
                if (!parent->left) {
                    parent->left = node;
                } else {
                    parent->right = node;
                }
            }

            // Push current node onto the stack
            st.push({node, depth});
        }

        // Root node is the bottom-most element in the stack
        while (st.size() > 1) {
            st.pop();
        }
        return st.top().first;
    }
};
