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
    string tree2str(TreeNode* root) {
        string result = "";
        check(root, result);
        return result;
    }

    void check(TreeNode* root, string &result){
        if (root == NULL) return;
        result += to_string(root->val);
        if ((root->left)!=NULL || (root->right)!=NULL){
            result += '(';
            check(root->left, result);
            result += ')';
        }
        if ((root->right)!=NULL){
            result += '(';
            check(root->right, result);
            result += ')';
        }
    }
};

// Reference from lancertech6's solution.
// This is my first time to code about binary tree, and it's difficult, QQ.