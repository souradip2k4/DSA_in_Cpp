// https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
// 104. Maximum Depth of Binary Tree
#include<bits/stdc++.h>
#include<TreeNode.h>
using namespace std;


class Solution {
  public:
  int maxDepth(TreeNode* root) {
    if (root == nullptr) return 0;

    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);

    return 1 + max(lh, rh);
  }
};
