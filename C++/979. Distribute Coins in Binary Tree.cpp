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
    int distributeCoins(TreeNode* root) {
        int ans = 0;
        balance(root, ans);
        return ans;
    }
private:
    int balance(TreeNode* root, int& ans) {
        if (!root) return 0;
        int left_ = balance(root->left, ans);
        int right_ = balance(root->right, ans);
        ans += abs(left_) + abs(right_);
        return root->val - 1 + left_ + right_;
    }
};

// Reference from 花花酱 LeetCode 979. Distribute Coins in Binary Tree - 刷题找工作 EP243, https://youtu.be/zQqku1AXVF8.