class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Base case: if both trees are NULL, they are the same
        if (!p && !q) {
            return true;
        }
        // If one of the trees is NULL and the other is not, they are different
        if (!p || !q) {
            return false;
        }
        // Check if the current node values are equal
        if (p->val != q->val) {
            return false;
        }
        // Recursively check the left and right subtrees
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};