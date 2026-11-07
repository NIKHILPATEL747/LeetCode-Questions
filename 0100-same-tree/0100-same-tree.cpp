class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<pair<TreeNode*, TreeNode*>> s;
        s.push({p, q});

        while (!s.empty()) {
            auto [node1, node2] = s.top();
            s.pop();

            if (!node1 && !node2) continue;
            if (!node1 || !node2 || node1->val != node2->val) return false;

            s.push({node1->right, node2->right});
            s.push({node1->left, node2->left});
        }

        return true;
    }
};