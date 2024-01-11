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
    int maxAncestorDiff(TreeNode* root) {
        if (root == NULL) return 0;
        int result = 0;
        int minVal = root->val;
        int maxVal = root->val;
        check(root, minVal, maxVal, result);
        return result;
    }
    void check(TreeNode* root, int minVal, int maxVal, int &result){
        if (root == NULL) return;
        minVal = min(minVal, root->val);
        maxVal = max(maxVal, root->val);
        // cout<<"result: "<<result<<", "<<"root: "<<root->val<<", "<<"minVal: "<<minVal<<", "<<"maxVal: "<<maxVal<<endl;
        result = max(result, max(abs(minVal - root->val), abs(maxVal - root->val)));
        check(root->left, minVal, maxVal, result);
        check(root->right, minVal, maxVal, result);
    }
};

// Reference from lancertech6's solution.