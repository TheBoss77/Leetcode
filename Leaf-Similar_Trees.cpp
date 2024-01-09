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
vector<int> sequence(TreeNode* root){
    if(root == nullptr)return {};
    if(root->left == nullptr && root->right == nullptr){
        return {root->val};
    }
    vector<int> ans = {};
    vector<int> left = sequence(root->left);
    vector<int> right = sequence(root->right);
    ans.insert(ans.end(), left.begin(), left.end());
    ans.insert(ans.end(), right.begin(), right.end());
    return ans;
}
bool leafSimilar(TreeNode* root1, TreeNode* root2){
    if(sequence(root1) == sequence(root2))return true;
    return false;
}
int main()
{
    
    return 0;
}