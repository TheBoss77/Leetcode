#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
vector<int> maxdiff(TreeNode* root){
    int big = root->val, small = root->val, diff = 0;
    if(root->left != nullptr){
        vector<int> l = maxdiff(root->left);
        if(l[0] > big)big = l[0];
        if(l[1] < small)small = l[1];
        diff = max(diff, big - root->val);
        diff = max(diff, root->val - small);
        diff = max(diff, l[2]);
    }
    if(root->right != nullptr){
        vector<int> r = maxdiff(root->right);
        if(r[0] > big)big = r[0];
        if(r[1] < small)small = r[1];
         diff = max(diff, big - root->val);
        diff = max(diff, root->val - small);
        diff = max(diff, r[2]);
    }
    return {big, small, diff};
}
int maxAncestorDiff(TreeNode* root) {
    vector<int> ans = maxdiff(root);
    return ans[2];
}
int main()
{

    return 0;
}