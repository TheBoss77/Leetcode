#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>
using namespace std;
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// int distancetoroot(TreeNode* root, int val){
//     if(root == nullptr)return 20000000;
//     if(root->val == val)return 0;
//     return 1 + max(distancetoroot(root->left, val), distancetoroot(root->right, val));
// }
// int maxdistance(TreeNode* root, int val){
//     if(root == nullptr)return 0;
//     if(root->val == val)return -20000000;
//     return 1 + max(maxdistance(root->left, val), maxdistance(root->right, val));
// }
// int m(TreeNode* root){
//     if(root == nullptr)return 0;
//     return 1 + max(m(root->left), m(root->right));
// }
// TreeNode* starttoend(TreeNode* root, int val){
//     if(root == nullptr)return nullptr;
//     if(root->val == val)return root;
//     TreeNode* left = starttoend(root->left, val);
//     TreeNode* right = starttoend(root->right, val);
//     if(left != nullptr){
//         return left;
//     }
//     return right;
// }
// vector<int> graph[100000];
// void change(TreeNode* root){
//     if(root == nullptr)return;
//     if(root->left != nullptr){
//         graph[root->val].push_back(root->left->val);
//         graph[root->left->val].push_back(root->val);
//         change(root->left);
//     }
//     if(root->right != nullptr){
//         graph[root->val].push_back(root->right->val);
//         graph[root->right->val].push_back(root->val);
//         change(root->right);
//     }
//     return;
// }
// int amountOfTime(TreeNode* root, int start) {
//     // int dtr = distancetoroot(root, start);
//     // int other = dtr + maxdistance(root, start);
//     // int second = m(starttoend(root, start));
//     // return max(second, other);
//     change(root);
//     bool visited[100000];
//     int distance[100000];
//     queue<int> q;
//     visited[start] = true;
//     q.push(start);
//     int m = 0;
//     while(!q.empty()){
//         for(int i = 0; i < graph[q.front()].size(); i++){
//             if(visited[graph[q.front()][i]] == false){
//                 q.push(graph[q.front()][i]);
//                 visited[graph[q.front()][i]] = true;
//                 distance[graph[q.front()][i]] = distance[i] + 1;
//                 m = max(m, distance[graph[q.front()][i]]);
//             }
//         }
//         q.pop();
//     }
//     return m;
// }
unordered_map<int, vector<int>> graph;

    int amountOfTime(TreeNode* root, int start) {
        constructGraph(root);

        queue<int> q;
        q.push(start);

        unordered_set<int> visited;

        int minutesPassed = -1;

        while (!q.empty()) {
            ++minutesPassed;
            for (int levelSize = q.size(); levelSize > 0; --levelSize) {
                int currentNode = q.front();
                q.pop();
                visited.insert(currentNode);
                for (int adjacentNode : graph[currentNode]) {
                    if (!visited.count(adjacentNode)) {
                        q.push(adjacentNode);
                    }
                }
            }
        }

        return minutesPassed;
    }

    void constructGraph(TreeNode* root) {
        if (!root) return;

        if (root->left) {
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
        }

        if (root->right) {
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
        }

        constructGraph(root->left);
        constructGraph(root->right);
    }
int main()
{

    return 0;
}