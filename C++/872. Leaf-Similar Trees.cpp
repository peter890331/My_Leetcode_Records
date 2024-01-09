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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> vector1;
        vector<int> vector2;
        check(root1, vector1);
        check(root2, vector2);
        // print(vector1);
        // print(vector2);
        return (vector1==vector2) ? true: false;
    }

    void check(TreeNode* root, vector<int>& vector){
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr){
            vector.push_back(root->val);
            return;
        }
        check(root->left, vector);
        check(root->right, vector);
    }

    void print(vector<int> vector){
        for (int i=0; i<vector.size(); i++) cout<<vector[i]<<',';
        cout<<endl;
    }
};

// Reference from lancertech6's solution.
// 深度优先搜索 (Depth-First Search, DFS) 的函数，用于找到二叉树中的叶子节点。