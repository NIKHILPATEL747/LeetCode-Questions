class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode(-1);
        TreeNode* curr = dummy;
        TreeNode* node = root;

        while (node) {
            if (node->left) {
                TreeNode* pred = node->left;
                while (pred->right && pred->right != node) {
                    pred = pred->right;
                }
                if (!pred->right) {
                    pred->right = node;
                    node = node->left;
                } else {
                    pred->right = nullptr;
                    curr->right = node;
                    node->left = nullptr;
                    curr = node;
                    node = node->right;
                }
            } else {
                curr->right = node;
                node->left = nullptr;
                curr = node;
                node = node->right;
            }
        }
        return dummy->right;
    }
};
