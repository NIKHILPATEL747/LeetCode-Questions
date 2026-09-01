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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {

        if (root1 == NULL && root2 == NULL) {
            return NULL;
        }

    
        int val1 = 0;
        int val2 = 0;
        if (root1 != NULL) val1 = root1->val;
        if (root2 != NULL) val2 = root2->val;

        
        TreeNode* newNode = new TreeNode(val1 + val2);


        TreeNode* left1 = NULL;
        TreeNode* left2 = NULL;
        if (root1 != NULL) left1 = root1->left;
        if (root2 != NULL) left2 = root2->left;
        newNode->left = mergeTrees(left1, left2);

        TreeNode* right1 = NULL;
        TreeNode* right2 = NULL;
        if (root1 != NULL) right1 = root1->right;
        if (root2 != NULL) right2 = root2->right;
        newNode->right = mergeTrees(right1, right2);

        return newNode;
    }
};
