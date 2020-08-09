bool comp(pair<int,int> &a, pair<int,int> &b)
    {
        if (a.first==b.first)
            return a.second<b.second;
        return a.first>b.first;
    }
class Solution {
    map<int,vector<pair<int,int>>> trav;
public:
    void preorder(TreeNode *root, int x, int y)
    {
        if (root==NULL)
            return;
        if (trav.find(x)==trav.end())
            trav[x]=vector<pair<int,int>>();
        trav[x].push_back({y,root->val});
        preorder(root->left,x-1,y-1);
        preorder(root->right,x+1,y-1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        preorder(root,0,0);
        vector<vector<int>> res;
        for (auto i=trav.begin();i!=trav.end();i++)
            sort(i->second.begin(),i->second.end(),comp);
        for (auto x:trav)
        {
            vector<int> temp;
            for (auto y:x.second)
                temp.push_back(y.second);
            res.push_back(temp);
        }
        return res;
    }
};