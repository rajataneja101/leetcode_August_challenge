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
    void Solve(TreeNode* root, int &sum){
        if(root==NULL){
            return;
        }
        if(root->left && (root->left->left==NULL && root->left->right==NULL)){
            cout<<root->left->val<<endl;
            sum+=root->left->val;
        }
        Solve(root->left, sum);
        Solve(root->right, sum);
        return;
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int sum=0;
        Solve(root, sum);
        return sum;
    }
};