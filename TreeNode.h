#include <iostream>
#include <vector>
#include <algorithm>

#pragma once

class TreeNode
{
public:
    int *data;
    TreeNode* left, *right;
    explicit TreeNode(int *data): data(data), left(nullptr), right(nullptr) {};
    ~TreeNode();

    static unsigned int kLeastCount;
    static void kthSmallest(TreeNode* root);
    static void inOrder(TreeNode* root);
    static TreeNode* buildBalancedTree(std::vector<int>& sortArray);
    static void PostOrderDestroy(TreeNode* root);
};






