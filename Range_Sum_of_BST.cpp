#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    // TreeNode() : val(0), left(nullptr), right(nullptr) {}
    // TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    // TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
int subtree(TreeNode* curr, int low, int high){
    int ans = 0;
    if(curr == nullptr)return 0;
    if(curr->val >= low && curr->val <= high){
        ans+=curr->val;
    }
    return ans + subtree(curr->left, low, high) + subtree(curr->right, low, high);
}
int rangeSumBST(TreeNode* root, int low, int high) {
    return subtree(root, low, high);
}
int main()
{

    return 0;
}