// https://leetcode.com/problems/binary-tree-preorder-traversal/
// 144. Binary Tree Preorder Traversal

#include<bits/stdc++.h>
#include<TreeNode.h>

using namespace std;

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
