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
    void dfs(TreeNode* root,int sum,int cur,int &ans){
        if(root){
            cur+=root->val;
            if(cur==sum){
                ans++;
            }
            dfs(root->left,sum,cur,ans);
            dfs(root->right,sum,cur,ans);
        }
    }
    
    void fromNode(TreeNode *root,int sum,int &ans){
        if(root){
            dfs(root,sum,0,ans);
            fromNode(root->left,sum,ans);
            fromNode(root->right,sum,ans);
        }        
    }
    
    int pathSum(TreeNode* root, int sum) {
        int ans=0;
        fromNode(root,sum,ans);
        return ans;
    }
};