// https://leetcode.com/problems/binary-tree-preorder-traversal/
// 144. Binary Tree Preorder Traversal

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

void preorder(TreeNode* node, vector<int>& arr) {
  if (node == nullptr) return;

  arr.push_back(node->val);
  preorder(node->left, arr);
  preorder(node->right, arr);
}

vector<int> preorderTraversal(TreeNode* root) {
  vector<int> res;
  preorder(root, res);
  return res;
}
