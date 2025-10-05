// https://leetcode.com/problems/binary-tree-level-order-traversal/

// 102. Binary Tree Level Order Traversal

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

vector<vector<int>> levelOrder(TreeNode* root) {

  vector<vector<int>> ans;
  if (root == nullptr) return ans;

  queue<TreeNode*> q;
  q.push(root);

  while (!q.empty()) {
    int size = q.size();
    vector<int> level;

    for (int i = 0; i < size; i++) {
      TreeNode* elem = q.front();
      q.pop();

      if (elem->left != nullptr) q.push(elem->left);
      if (elem->right != nullptr) q.push(elem->right);
      level.push_back(elem->val);
    }

    ans.push_back(level);
  }

  return ans;
}